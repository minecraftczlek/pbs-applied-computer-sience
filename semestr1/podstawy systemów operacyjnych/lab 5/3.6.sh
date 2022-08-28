#!/bin/bash
poprzednia=0
nastepna=1
max=$1
funkcja (){
    if [ $1 != $max ]; then
        wynik=$[$poprzednia + $nastepna]
        poprzednia=$nastepna
        nastepna=$wynik
        funkcja $[$1 + 1]
    fi
}
if [ $1 == 0 ] ; then
    wynik=0
elif [ $1 == 1 ] ; then
    wynik=1
else
    funkcja 1
fi
echo $wynik