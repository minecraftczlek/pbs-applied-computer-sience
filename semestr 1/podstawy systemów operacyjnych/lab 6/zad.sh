#!/bin/bash
answer="y"
while [ $answer = "y" ] ||[ $answer = "Y" ]
do
	ls -a
	echo -n "Podaj nazwę pliku: "
	read file
	if [ -e $file ]; then
		echo "Ten plik istnieje"
		rm $file
	else
		echo "Plik nie istnieje"
	fi
	echo -n "Czy dalej chcesz usuwac pliki? [Y/N] "
	read answer
done
