#!/bin/bash
echo "Zastosowanie regex:"
echo "-------------------"

cat listing.txt | gawk '{print $8}'
echo "drugi raz: dla nazwy Ala "
cat listing.txt | gawk -F " " '/Ala*/ {print $9}'
echo "----kolejna część---"
echo -e "Właśnie uruchamiasz skrypt bash\m teraz drugi wiersz" | gawk '{print $1}'
echo
cat /etc/passwd | gawk -F: '/^[rs]/ {print $1}'