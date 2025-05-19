# Epytodo

## Description

**Epytodo** est une application web de type _To-do List_ développée en Python avec le framework Flask et une base de données MySQL.  

Elle permet aux utilisateurs de s'inscrire, se connecter, créer, modifier et supprimer des tâches.

## Fonctionnalités

- Authentification utilisateur (inscription et connexion)
- Création, modification, suppression de tâches
- Affichage des tâches liées à un utilisateur
- Base de données relationnelle avec MySQL
- Architecture MVC (Modèle-Vue-Contrôleur)
- Rendu HTML avec Postman

## Technologies utilisées

- Python 3
- MySQL
- HTML/CSS(pour les pages web)
- bcrypt(pour le hash des mots de passe)

## Installation

`npm intall`
`npm install express`
`npm init`

### Prérequis

- Python 3.x
- MySQL Server
- `pip` (gestionnaire de paquets Python)

### Clonage du projet


`git clone https://github.com/B-WEB-200-COT-2-1-epytodo-stella.gbaguidi.git`

`cd epytodo`

Installation des dépendances

`pip install -r requirements.txt`

Configuration de la base de données

	1.	Connecte-toi à MySQL :

`mysql -u root -p`

	2.	Exécute le script SQL :

`SOURCE epytodo.sql`

	3.	Modifie les informations de connexion MySQL dans config.py si nécessaire :

```bash

DB_CONFIG = {
    'host': 'localhost',
    'user': 'root',
    'password': 'votre_mot_de_passe',
    'database': 'epytodo'
}

```

#### Lancement de l’application

`node src\index.js`

Ouvre ton navigateur à l’adresse suivante :
http://localhost:3000

##### Structure du projet

epytodo/

│

├── run.py               # Point d'entrée de l'application

├── config.py            # Configuration de la BDD

├── controller.py        # Logique de traitement

├── views.py             # Définition des routes Flask

├── models.py            # Requêtes SQL

├── templates/           # Fichiers HTML Jinja2

│   ├── login.html

│   ├── register.html

│   └── dashboard.html

├── static/              # Fichiers CSS / JS

│
└── epytodo.sql          # Script SQL pour la base de données

###### Routes principales

Méthode 	Route   	Description
POST	/register	    Créer un compte
POST	/login	        Connexion
GET	    /tasks	            Liste des tâches
POST	/tasks/add	    Ajouter une tâche
POST	/tasks/edit	    Modifier une tâche
POST	/tasks/delete	Supprimer une tâche

###### Auteurs
        Miranice ADJOVI - miranice.adjovi@epitech.eu
        Stella GBAGUIDI  - stella.gbaguidi@epitech.eu
        Yann DOSSOU - yann.dossou@epitech.eu  