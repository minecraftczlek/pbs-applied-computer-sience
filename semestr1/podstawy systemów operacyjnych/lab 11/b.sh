#!/bin/bash
echo "podaj ilość plików"
read n
echo "podaj nazwę pliku"
read nazwa

autor=`whoami`

for (( i=0;i<$n;i++)); do 

    cat <<EOF1 > $nazwa$i.sh
#!/bin/bash
ls -a
echo "autorem pliku jest $autor
EOF1

    chmod 711 $nazwa$i.sh

done