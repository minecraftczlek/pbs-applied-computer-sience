#!/bin/bash
if [ $# != 0 ]; then
    nazwa=$1
else
    nazwa="plik"
fi
if [ $2 ];then
    s=$2
else 
    s=10
fi
if [ $3 ];then
    ext=$3
else 
    s="txt"
fi
for i in `seq 1 $s`; do
    touch $nazwa$i.$ext
done
echo "utworzono $i plików"
ls $plik*.$ext