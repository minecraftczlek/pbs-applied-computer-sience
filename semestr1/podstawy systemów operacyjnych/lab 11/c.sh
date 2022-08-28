#!/bin/bash
suma=0

for ((;;)); do
    echo -n "podaj liczbę: "
    read x
    if [ $x = 0 ]; then
        echo $suma
        break
    fi
    suma=$[suma + x]
done