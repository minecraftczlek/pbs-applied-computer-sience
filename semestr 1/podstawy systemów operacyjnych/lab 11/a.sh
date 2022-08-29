#!/bin/bash
echo "Podaj opcje"
opcje=("usuwanie wierszy" "wyświetlanie plików" "wyjście")
select opc in "${opcje[@]}"
do
    case $opc in
        "usuwanie wierszy")
            echo "Podaj nazwę pliku: "
            read plik  
            grep  -v '^[[:space:]]*$' $plik > a.cache
            cat a.cache > $plik
            rm a.cache
            ;;
        "wyświetlanie plików")
            ls -a;;
        "wyjście")
            break;;
    esac
done