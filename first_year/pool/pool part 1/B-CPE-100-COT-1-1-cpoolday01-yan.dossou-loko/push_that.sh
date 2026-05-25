#!/bin/bash

if [ -z "$1" ]; then
 echo "Erreur : Vous devez fourir un message de commit."
 exit 1
fi

git add .

git commit -m "$1"

if [ $? -ne 0 ]; then
 echo "Aucun changement à committer, mais on tente de pousser quand même."
fi

git push

if [ $? -eq 0 ]; then
 echo "Push réussi !"
else
 echo "Erreur lors du push."
fi

