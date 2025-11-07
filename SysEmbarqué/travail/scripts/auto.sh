#!/bin/bash
echo "#######################"
echo "# Compilation Arduino #"
echo "#######################"

if [[ $# -eq 0 || $1 == "help" ]] ; then
    echo "---------------------------------------------------------"
    echo "Utilisation : $0 f=<nom_du_dossier> [p=</dev/nom_du_port>]"
    echo "---------------------------------------------------------"
    exit 1
fi

PORT="/dev/ttyACM0"

for arg in "$@"; do
    case $arg in
        f=*)
            dossier="${arg#f=}" 
            ;;
            
        p=*)
            PORT="${arg#p=}"   
            ;;
        *)
                echo "Argument inconnu : $arg"
                exit 1
                ;;
    esac
done

if [ -d "$dossier" ]; then
    echo "Contenu du dossier '$dossier' :"
    ls -A "$dossier"
    printf "P1."
    cd "$dossier"
    if [ ! -d ".tmp" ]; then 
        mkdir ".tmp"
    else
        rm -rf .tmp/*
    fi
    if [ ! -d "build" ]; then 
        mkdir "build"
    else
        rm -rf build/*
    fi
    echo ". done [env ready]"
    printf "P2."
    for c in *.c; do
        [ -f "$c" ] || break
        avr-gcc -Os -DF_CPU=16000000L -mmcu=atmega328p -c "$c" -o .tmp/${c%.*}.o
        filesO="$filesO .tmp/${c%.c}.o"
    done
    echo ". done [-o ready]"
    printf "P3."
    avr-gcc -DF_CPU=16000000L -mmcu=atmega328p $filesO -o build/"$dossier"
    echo ". done [links]"
    printf "P4."
    avr-objcopy -O ihex -R .eeprom build/"$dossier" build/"$dossier".hex
    echo ". done [.hex]"
    printf "Voulez-vous commencer le téléversement ? Y/N :"
    read -r TELEV
    if [ $TELEV == "N" ]; then
        echo "pas de téléversement"
        exit
    else
        echo "démarrage du téléversement sur le port ${PORT#/dev/tty}"
        avrdude -p atmega328p -c arduino -P $PORT -b 115200 -U flash:w:build/"$dossier".hex
        exit
    fi
else
    echo "Erreur : le dossier '$dossier' n'existe pas."
    exit 1
fi


