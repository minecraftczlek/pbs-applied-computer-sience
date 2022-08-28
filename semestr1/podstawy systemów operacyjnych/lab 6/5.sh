#!/bin/bash
echo -n "Podaj a: " 
read a
echo -n "Podaj b: "
read b
echo "$a"
select znak in dodawanie odejmowanie mnożenie dzielenie; do
    case $znak in
        dodawanie)
            wynik=$[ $a + $b]
            echo $wynik
            break;;
        odejmowanie)
            wynik=$[ $a - $b]
            echo $wynik
            break;;
        mnożenie)
            wynik=$[ $a * $b]
            echo $wynik
            break;;
        dzielenie)
            wynik=$[ $a / $b]
            echo $wynik
            break;;
        *)
            echo "zła operacja";;
    esac
done