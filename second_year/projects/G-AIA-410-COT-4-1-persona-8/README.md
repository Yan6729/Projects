# Persona — README Technique

> Agrégateur de newsletters personnalisées piloté par IA, sans interface graphique, construit sur N8N.

---

## Sommaire

1. [Vue d'ensemble](#vue-densemble)
2. [Prérequis](#prérequis)
3. [Installation](#installation)
4. [Structure du projet](#structure-du-projet)
5. [Base de données](#base-de-données)
6. [Workflows](#workflows)
7. [Utilisation](#utilisation)
8. [Sécurité](#sécurité)
9. [RGPD](#rgpd)
10. [Limitations connues](#limitations-connues)

---

## Vue d'ensemble

Persona est un système de newsletters entièrement automatisé. L'utilisateur interagit uniquement via un chatbot N8N, qui gère l'inscription, l'authentification, la configuration des préférences, et l'envoi automatique de newsletters personnalisées par email.

**Stack :**
- **N8N** (self-hosted) — orchestration des workflows
- **PostgreSQL** — stockage des utilisateurs et sessions
- **Google Gemini** — modèle LLM pour la génération de contenu
- **RSS** — sources d'actualités
- **SMTP** — envoi des emails

---

## Prérequis

- N8N (self-hosted, version récente)
- PostgreSQL accessible depuis N8N
- Un compte Google AI Studio (clé API Gemini)
- Un service SMTP configuré dans N8N (Gmail, Brevo, etc.)
- Node.js (si tu utilises des community nodes)

---

## Installation

### 1. Base de données

Exécute le fichier `db/persona.sql` sur ta base PostgreSQL :

```bash
psql -U <user> -d <database> -f db/persona.sql
```

Cela crée deux tables : `users` et `sessions`.

### 2. Credentials N8N

Dans N8N, configure les credentials suivants avant d'importer les workflows :

| Credential | Type | Utilisation |
|---|---|---|
| PostgreSQL | Postgres | Tous les workflows |
| Google Gemini API | Google AI | Chatbot, Newsletter |
| SMTP | Email | Newsletter |

### 3. Import des workflows

Importe les fichiers JSON dans cet ordre :

1. `create_session.json`
2. `check_session.json`
3. `delete_section.json`
4. `Register.json`
5. `Login.json`
6. `Preferences configuration.json`
7. `Newsletter.json`
8. `Chatbot.json`

> ⚠️ Les fichiers JSON exportés peuvent contenir des noms de credentials. Vérifie et anonymise ces informations avant tout partage.

### 4. Activer les workflows

Active tous les workflows dans N8N. Le trigger du **Newsletter** est schedulé — vérifie que le Schedule Trigger est bien activé.

---

## Structure du projet

```
persona/
├── db/
│   └── persona.sql               # Schéma PostgreSQL
├── Chatbot.json                  # Workflow principal (point d'entrée)
├── Register.json                 # Inscription utilisateur
├── Login.json                    # Authentification
├── create_session.json           # Création de token de session
├── check_session.json            # Vérification de session
├── delete_section.json           # Déconnexion / suppression de session
├── Preferences configuration.json # Mise à jour topics + schedule
└── Newsletter.json               # Génération et envoi des newsletters
```

---

## Base de données

### Table `users`

| Colonne | Type | Description |
|---|---|---|
| `id` | INT (auto) | Identifiant unique |
| `username` | VARCHAR(50) | Nom d'utilisateur |
| `email` | VARCHAR(255) | Adresse email (unique) |
| `password` | VARCHAR(255) | Mot de passe hashé |
| `birthdate` | DATE | Date de naissance |
| `topics` | VARCHAR(1024) | Centres d'intérêt (texte libre) |
| `schedule` | TIME | Heure d'envoi souhaitée (défaut : 08:00) |
| `created_at` | TIMESTAMP | Date de création du compte |

### Table `sessions`

| Colonne | Type | Description |
|---|---|---|
| `id` | SERIAL | Identifiant unique |
| `user_id` | INT (FK) | Référence vers `users.id` |
| `token` | VARCHAR(255) | Token de session (unique) |
| `created_at` | TIMESTAMP | Date de création |

---

## Workflows

### `Chatbot.json` — Point d'entrée principal

Déclenché par le **Chat Trigger** N8N. Contient un AI Agent (Gemini) avec les règles suivantes :

- Sans token en mémoire → propose uniquement login ou inscription
- Avec token → vérifie la session via `check_session` avant toute action
- Collecte les préférences manquantes (email, topics, schedule)
- Appelle les sous-workflows via des Tool Workflow nodes

**Outils disponibles pour l'agent :**

| Tool | Workflow appelé |
|---|---|
| Call 'Register' | `Register.json` |
| Call 'Login' | `Login.json` |
| Call 'check_session' | `check_session.json` |
| Call 'delete_section' | `delete_section.json` |
| Call 'Preferences' | `Preferences configuration.json` |

---

### `Register.json` — Inscription

1. Vérifie que le username n'est pas déjà pris (SELECT sur `users`)
2. Hashe le mot de passe (algorithme djb2 custom en JS)
3. Insère le nouvel utilisateur dans `users`
4. Appelle `create_session` pour créer un token
5. Retourne `{ success, token, username }`

---

### `Login.json` — Authentification

1. Récupère l'utilisateur par username (SELECT sur `users`)
2. Hashe le mot de passe fourni et compare avec le hash stocké
3. Si match → appelle `create_session`
4. Retourne `{ success, token, username }` ou `{ success: false }`

---

### `create_session.json` — Création de session

Génère un token aléatoire (3x `Math.random().toString(36)` + timestamp base36) et l'insère dans la table `sessions`.

---

### `check_session.json` — Vérification de session

Cherche le token dans la table `sessions`. Retourne `{ success: true }` si trouvé, `{ success: false }` sinon.

---

### `delete_section.json` — Déconnexion

Vérifie que la session existe, la supprime de la table `sessions`. Retourne le statut de l'opération.

---

### `Preferences configuration.json` — Mise à jour des préférences

Reçoit `username`, `topics`, `schedule` et met à jour la ligne correspondante dans `users`.

---

### `Newsletter.json` — Génération et envoi

**Déclencheur :** Schedule Trigger (toutes les minutes, filtre par heure dans le code)

**Flux :**

1. Récupère tous les utilisateurs depuis `users`
2. Filtre ceux dont le `schedule` correspond à l'heure courante
3. Agrège les articles depuis 7 sources RSS en parallèle :
   - CNN (`rss.cnn.com`)
   - BBC News (`feeds.bbci.co.uk`)
   - CCM Magazine (`ccmmagazine.com`)
   - Anime News Network (`animenewsnetwork.com`)
   - All About Romance (`allaboutromance.com`)
   - Café Astrology (`cafeastrology.com`)
   - Reddit r/DarkRomance
4. Pour chaque utilisateur éligible, envoie les articles + topics au LLM (Gemini) qui sélectionne les 5 plus pertinents et génère une newsletter HTML
5. Envoie l'email via SMTP

---

## Utilisation

### Démarrer une session

Ouvre le chat N8N (Chat Trigger). L'agent te guidera automatiquement :

```
Agent : Bonjour ! Souhaitez-vous vous connecter ou créer un compte ?

> Créer un compte
Agent : Quel nom d'utilisateur souhaitez-vous ?
...
```

### Configurer ses préférences

Une fois connecté, tu peux donner tes centres d'intérêt et l'heure d'envoi souhaitée directement dans le chat. L'agent met à jour le profil automatiquement.

### Se déconnecter

Dis simplement "déconnecte-moi" ou "logout" dans le chat.

---

## Sécurité

- **Authentification par session token** : chaque action sensible passe par `check_session`
- **Isolation des données** : l'agent ne peut accéder qu'aux données de l'utilisateur authentifié
- **Instructions système hardcodées** : l'agent ignore toute tentative de prompt injection
- **Pas d'accès admin via chat** : aucun workflow ne permet d'élever les privilèges

> ⚠️ **Limitation connue** : le hash utilisé (djb2) n'est pas cryptographiquement sûr. En production, remplacer par bcrypt ou argon2.

> ⚠️ **Limitation connue** : les tokens de session n'ont pas de date d'expiration. Ils restent valides jusqu'à déconnexion explicite.

---

## RGPD

| Point | État |
|---|---|
| Consentement au stockage de l'email | À implémenter (message explicite lors de l'inscription) |
| Droit à l'effacement | Partiellement implémenté via `delete_section` (supprime la session, pas le compte) |
| Droit d'accès aux données | Non implémenté |
| Désinscription newsletter | Non implémenté |
| Chiffrement des données au repos | Dépend de la config PostgreSQL |

---

## Limitations connues

- Le hash de mot de passe (djb2) n'est pas adapté à la production
- Les sessions n'expirent pas automatiquement
- Le Schedule Trigger tourne à chaque minute — à optimiser selon le volume
- Les sources RSS sont hardcodées dans le workflow Newsletter
- Pas de gestion des erreurs d'envoi email (pas de retry)
- Pas de désinscription automatique (lien unsubscribe manquant dans les emails)