#!/bin/bash
i=1
until(( $i>5 )); do
    echo "$i "
    i=$[$i+1]
done