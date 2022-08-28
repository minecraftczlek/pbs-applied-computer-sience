#!/bin/bash
if [ -e ${1} ]; 
then echo "plik istnieje"
else echo "To jest nowy plik studenta: 118832" > ${1}
fi