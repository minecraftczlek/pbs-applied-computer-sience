#!/bin/bash
silnia () {
    # treść funkcji; $1 jest argumentem funkcji
    if [ $1 == 0 ] ; then
        wynik=1
    else
        silnia $[$1 - 1]
        wynik=$[wynik * $1]
    fi
}
# wywołanie funkcji; $1 jest argumentem skryptu
silnia $1
echo $wynik
