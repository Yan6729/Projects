# RFC (informel) — Protocole applicatif MyTeams

**Statut :** description de l’implémentation courante (`myteams_server` / `myteams_cli`).  
**Transport :** TCP, port unique, une session TCP par client.  
**Encodage :** UTF-8.  
**Version :** 1 (texte ligne par ligne).

---

## 1. Introduction

Ce document spécifie le dialogue **texte** entre le client et le serveur : commandes envoyées par le client, réponses et **notifications asynchrones** (événements poussés sur la même socket).

Contraintes alignées sur le sujet :

- Commandes : préfixe `/`, arguments **obligatoirement** entre guillemets doubles `"..."`.
- Longueurs : nom 1..32, description 1..255, corps de message / commentaire 1..512 (comptage en **caractères Unicode**, comme `chars().count()` en Rust).
- Les champs texte ne doivent pas contenir de **TAB** (`U+0009`) sur le fil : le serveur remplace les tabulations par un espace ASCII dans les payloads tabulés.

---

## 2. Transport et cadrage des messages

### 2.1. Lignes

- Chaque **commande** client est une ligne terminée par `\n` (séquence `\r\n` acceptée en entrée côté serveur si le buffer normalise les fins de ligne).
- Chaque **réponse** ou **événement** serveur est une ligne terminée par `\n`.
- Le serveur peut envoyer **plusieurs lignes** consécutives pour une seule commande (listes, puis ligne de fin).

### 2.2. Format tabulé

Les lignes structurées utilisent le **caractère TAB** (`\t`) comme séparateur de champs :

```
TYPE_CHAMP<TAB>champ1<TAB>champ2<...>
```

Le premier champ est un **mot-clé** (ex. `USER`, `LIST_TEAM`, `SYS_LOGIN`). Les lignes commençant par `ERR ` sont des erreurs texte (espaces, pas de tabulation obligatoire).

### 2.3. Commandes client

Syntaxe générale :

```
/commande "arg1" "arg2" ...
```

Espaces entre les arguments. Tout le reste après le nom de commande est parsé comme suite de chaînes `"..."`.

Erreurs de parsing (préfixe `ERR ` + message) :

| Condition | Message (corps après `ERR `) |
|-----------|-------------------------------|
| Argument sans guillemet ouvrant | `tous les arguments doivent etre entre guillemets` |
| Guillemet fermant absent | `guillemet fermant manquant` |

Si la ligne ne commence pas par `/` :

```
ERR usage: command must start with '/'
```

---

## 3. Identifiants et temps

- **Utilisateurs, équipes, canaux, fils :** identifiant **UUID v4** (chaîne 36 caractères avec tirets, ex. `a1b2c3d4-e5f6-4789-a012-3456789abcde`), généré côté serveur (`/dev/urandom` sous Unix, repli déterministe sinon).
- **Horodatage :** entier signé 64 bits, secondes Unix (champs `ts` / timestamps dans les listes et événements).

---

## 4. Modèle de sécurité (aperçu)

- Sans `/login` réussi : le serveur refuse les commandes métier avec `ERR vous devez etre connecte` (sauf `/help`).
- `/users`, `/user`, messages privés, abonnements, créations, listes, infos : **réservés aux clients authentifiés** (`user_id` défini).
- Création de canal / fil / réponse : l’utilisateur doit être **abonné** à l’équipe concernée.
- `/subscribed "team_uuid"` (membres) : le demandeur doit être abonné à cette équipe.
- Les événements `SYS_*` poussés aux autres clients respectent les règles d’abonnement (voir section 6).

---

## 5. Commandes et réponses (requête → réponse)

### 5.1. `/help`

**Réponse :** une ligne unique (pas de tabulation) :

```
OK /help /login /logout /users /user /send /messages /subscribe /subscribed /unsubscribe /create /list /info
```

### 5.2. `/login "user_name"`

- Nom : longueur 1..32.
- Si le nom est nouveau : création d’un utilisateur (journalisation côté serveur via la bibliothèque fournie).

**Réponse au client :**

```
OK logged_in<TAB><user_uuid><TAB><user_name>
```

`<user_name>` : les TAB du nom sont remplacés par des espaces sur le fil.

**Notification aux autres clients connectés et authentifiés** (toutes sessions sauf l’émetteur) :

```
SYS_LOGIN<TAB><user_uuid><TAB><user_name>
```

Erreurs typiques : mauvais nombre d’arguments, nom trop court/long.

### 5.3. `/logout`

**Réponse :**

```
OK logged_out<TAB><user_uuid><TAB><user_name>
```

**Notification aux autres** :

```
SYS_LOGOUT<TAB><user_uuid><TAB><user_name>
```

La session TCP peut rester ouverte ; le client n’est plus considéré comme authentifié côté serveur pour cette connexion.

### 5.4. `/users`

**Réponse :** une ligne par utilisateur du domaine, puis fin de liste :

```
USER<TAB><uuid><TAB><name><TAB><status>
...
OK fin de la liste des utilisateurs
```

`<status>` : entier `0` (hors ligne) ou `1` (au moins une connexion TCP authentifiée avec cet uuid).

### 5.5. `/user "user_uuid"`

Une ligne `USER` comme ci-dessus, ou erreur `ERR utilisateur inconnu`.

### 5.6. `/send "user_uuid" "message_body"`

- Destinataire doit exister.
- Corps : 1..512 caractères.

**Réponse à l’émetteur :**

```
OK_DM_SENT
```

**Notification au destinataire** (si connecté et authentifié, et si expéditeur ≠ destinataire) :

```
SYS_DM<TAB><from_uuid><TAB><to_uuid><TAB><timestamp><TAB><body>
```

Les TAB dans le corps sont remplacés par des espaces.

### 5.7. `/messages "user_uuid"`

Historique entre l’utilisateur courant et l’interlocuteur, ordre serveur (ordre d’insertion en mémoire) :

```
DM<TAB><from_uuid><TAB><to_uuid><TAB><timestamp><TAB><body>
...
OK fin des messages
```

### 5.8. `/subscribe "team_uuid"`

**Réponse :**

```
OK_SUBSCRIBED<TAB><user_uuid><TAB><team_uuid>
```

### 5.9. `/subscribed`

Sans argument : équipes auxquelles l’utilisateur est abonné.

```
LIST_TEAM<TAB><team_uuid><TAB><name><TAB><description>
...
OK fin des equipes abonnees
```

### 5.10. `/subscribed "team_uuid"`

Membres abonnés à l’équipe (le demandeur doit être abonné).

```
USER<TAB><uuid><TAB><name><TAB><status>
...
OK fin des membres de l'equipe
```

### 5.11. `/unsubscribe "team_uuid"`

```
OK_UNSUBSCRIBED<TAB><user_uuid><TAB><team_uuid>
```

### 5.12. `/create`

Toujours authentifié. Le **nombre d’arguments** détermine l’opération (le client CLI reconstruit la ligne à partir du contexte `/use`).

| # args | Signification | Condition d’accès |
|--------|----------------|-------------------|
| 2 | Créer une **équipe** (nom, description) | — |
| 3 | Créer un **canal** (team_uuid, nom, description) | Abonné à l’équipe |
| 4 | Créer un **fil** OU un **commentaire** (team, channel, 3ᵉ, 4ᵉ) | Abonné ; si le 3ᵉ argument est l’uuid d’un **fil existant** dans le canal → **commentaire** (4ᵉ = corps) ; sinon → **nouveau fil** (3ᵉ = titre 1..32, 4ᵉ = message initial 1..255) |

**Réponses « initiateur » :**

- Équipe :

```
OK_TEAM_CREATED<TAB><team_uuid><TAB><name><TAB><description>
```

- Canal :

```
OK_CH_CREATED<TAB><channel_uuid><TAB><name><TAB><description>
```

- Fil :

```
OK_TH_CREATED<TAB><thread_uuid><TAB><creator_uuid><TAB><timestamp><TAB><title><TAB><initial_body>
```

- Commentaire :

```
OK_RP_CREATED<TAB><thread_uuid><TAB><author_uuid><TAB><timestamp><TAB><body>
```

À la création d’équipe, le créateur est **automatiquement abonné**.

### 5.13. `/list`

Authentifié. `0` à `3` arguments : équipe, canal, fil de discussion.

| Args | Contenu |
|------|---------|
| 0 | Toutes les équipes du domaine |
| 1 | Canaux de l’équipe (l’équipe doit exister) |
| 2 | Fils du canal |
| 3 | Réponses du fil (y compris le message initial du fil, formaté comme une ligne `LIST_RP`) |

Lignes de données :

```
LIST_TEAM<TAB><uuid><TAB><name><TAB><description>
LIST_CH<TAB><uuid><TAB><name><TAB><description>
LIST_TH<TAB><thread_uuid><TAB><creator_uuid><TAB><timestamp><TAB><title><TAB><initial_body>
LIST_RP<TAB><thread_uuid><TAB><author_uuid><TAB><timestamp><TAB><body>
```

Fin :

```
OK fin de la liste
```

### 5.14. `/info`

Authentifié.

| Args | Première ligne de données |
|------|---------------------------|
| 0 | `INFO_USER<TAB><uuid><TAB><name><TAB><status>` |
| 1 | `INFO_TEAM<TAB><uuid><TAB><name><TAB><description>` |
| 2 | `INFO_CH<TAB><uuid><TAB><name><TAB><description>` |
| 3 | `INFO_TH<TAB><thread_uuid><TAB><creator_uuid><TAB><timestamp><TAB><title><TAB><initial_body>` |

Puis systématiquement :

```
OK fin des informations
```

---

## 6. Notifications asynchrones (`SYS_*`)

Envoyées sur la socket **sans commande** associée du côté récepteur. Résumé :

| Ligne | Destinataires | Description |
|-------|----------------|-------------|
| `SYS_LOGIN` | Tous les clients **authentifiés**, sauf l’émetteur | Connexion d’un utilisateur |
| `SYS_LOGOUT` | Idem | Déconnexion |
| `SYS_TEAM` | Tous les clients **authentifiés** (y compris le créateur) | Nouvelle équipe |
| `SYS_CH` | Abonnés à l’équipe, **sauf** le créateur du canal | Nouveau canal |
| `SYS_TH` | Abonnés à l’équipe, **sauf** le créateur du fil | Nouveau fil |
| `SYS_REPLY` | Abonnés à l’équipe, **sauf** l’auteur du commentaire | Nouvelle réponse (`SYS_REPLY<TAB><team><TAB><channel><TAB><thread><TAB><user><TAB><body>`) |
| `SYS_DM` | Utilisateur destinataire connecté | Message privé entrant |

Le client graphique / CLI doit mapper ces lignes vers les fonctions **`client_event_*`** de la bibliothèque fournie (affichage sur la sortie gérée par la lib — ne pas écrire sur stderr manuellement pour les données serveur).

---

## 7. Persistance

- Fichier dans le répertoire de travail du serveur : **`myteams_save.db`**.
- Écriture à l’arrêt du processus (ex. Ctrl+C géré dans la boucle d’événements).
- Relecture au démarrage si le fichier est présent (utilisateurs, équipes, canaux, fils, réponses, messages privés, abonnements — format interne texte du projet).

---

## 8. Client CLI et `/use`

La commande **`/use`** est interprétée **uniquement en local** par `myteams_cli` : elle fixe le contexte (équipe / canal / fil) utilisé pour construire les lignes `/create`, `/list`, `/info` envoyées au serveur (préfixe des uuid requis selon la profondeur du contexte).

---

## 9. Messages d’erreur (`ERR ...`)

Les erreurs sont des lignes texte préfixées par `ERR ` (espace). Les libellés sont en **français** dans cette implémentation (ex. `ERR equipe inconnue`, `ERR vous devez etre connecte`, `ERR commande inconnue`). Toute automatisation externe doit se baser sur le préfixe `ERR ` ou sur des correspondances exactes avec cette version.

---

## 10. Références

- Sujet PDF MyTeams (Epitech) : contraintes Makefile, TCP `std::net`, absence de crates externes, absence de threads côté serveur, journalisation via la bibliothèque C.
- En-têtes : `libs/myteams/logging_server.h`, `libs/myteams/logging_client.h` — liste exhaustive des événements à journaliser / afficher.
