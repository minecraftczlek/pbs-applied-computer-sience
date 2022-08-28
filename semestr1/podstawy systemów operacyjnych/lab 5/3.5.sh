#!/bin/bash
args=("$@") 
# pobieranie wszystkich argumentów do jednej tablicy
for (( i=$#-1;i>=0;i--)); do 
    # iterowanie wszytskich elementów tablicy od końca
    echo -n "${args[${i}]} "
    # wyświetlanie argumentu
done
echo 
# znak nowej lini