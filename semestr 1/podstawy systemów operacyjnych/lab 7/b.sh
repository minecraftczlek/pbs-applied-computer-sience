#!/bin/bash
echo "Podaj szukany wyraz"
read wyraz
echo "Podaj lokalizację wyszukiwania(\".\" to obecny katalog"
read l
cd $l
j=0
for i in *
do
    if more $i|grep -q $wyraz
    then
        echo $i
        j=$[$j+1]
    fi
done
echo "w katalogu $PWD znaleziono $j plikow"