#!/bin/bash

options=("Multiplayer - Same Keyboard" "Multiplayer - Network" "Exit")
select opt in "${options[@]}"
do
    case $opt in
        "Multiplayer - Same Keyboard")
            echo "Starting pong with same keyboard controls"
            ./Client/pong -m -k
            ;;
        "Multiplayer - Network")
            echo "Starting pong with socket connection"
            ./Client/pong -m -s
            ;;
        "Exit")
            break
            ;;
        *)
            echo "Invalid option";;
    esac
done