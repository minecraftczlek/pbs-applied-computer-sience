#!/bin/bash
if [ ! -d ~/KOSZ/ ]; then
    mkdir ~/KOSZ
fi

for i in *
do
    if [ ! -d $i ]; then
        if ls $i|grep .txt >2; then
            mv $i ~/KOSZ/
            echo "Przeniesiono $i"
        fi
    fi
done
echo "zawartosc katalogu ~/KOSZ/ "
ls ~/KOSZ/
echo "czy chcesz oprożnic kosz? [T/N]"
read odpowiedz
if [ $odpowiedz == "T" ]; then
    rm ~/KOSZ/*
fi