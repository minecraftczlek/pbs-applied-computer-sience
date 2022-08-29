#!/bin/bash
opcje=("litery" "Backup" "kalendarz" "wyjście")
select opc in "${opcje[@]}"
do
    case $opc in
        "litery")
            echo "Podaj napis do transformacji: "
            read napis
            printf '%s\n' "$napis" | awk '{ print toupper($0) }';;
        "Backup")
            echo "przygotowuję kopię"
            cp -r /bin/ .
            echo "kopia przygotowana";;
        "kalendarz")
            cal;;
        "wyjście")
            break;;
    esac
done