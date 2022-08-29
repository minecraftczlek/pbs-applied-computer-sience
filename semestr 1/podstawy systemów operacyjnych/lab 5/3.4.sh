#!/bin/bash
funkcja (){
    for i; do
        # iteracja po wszystkich argumentach
        if [ $i != $1 ]; then
            # ignorowanie pierwszego argumentu
            x=$(find $i -type f -print | wc -l)
            # liczenie plików w danym folderze
            echo "$i $x"
        fi
    done
}
funkcja $(find $1 -maxdepth 1 -type d)
# szukam wszystkich podfolderów i wywołuje funkcję
echo "numer indeksu: 118832"