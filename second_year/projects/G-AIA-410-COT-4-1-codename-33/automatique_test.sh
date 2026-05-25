#!/bin/bash

ollama --version

MODEL="granite3.1-moe"
RESULT=$?

DEFENSE="$1"
ATTACK="$2"

if [ $RESULT -neq 0 ]; then
    if [ -z "$DEFENSE" ] || [ -z "$ATTACK" ]; then
        echo "Let's run the model first"
        DEFENSE_OUTPUT=$(ollama run "$MODEL" "$DEFENSE")
        echo "Defense response:"
        echo "$DEFENSE_OUTPUT"

        echo "
        
        
        
        "
        ATTACK_FORMATING="Defense configuration:\n$DEFENSE_OUTPUT\nAttack prompt:\n$ATTACK"
        ATTACK_OUTPUT=$(echo -e $ATTACK_FORMATING | ollama run $MODEL)

        echo "Result... :"
        echo "$ATTACK_OUTPUT"
    else
        echo "You must provide a defense prompt and an attack prompt"
        return
    fi
else
    echo "Sorry but it seems like you'll need to download ollama first"
fi 