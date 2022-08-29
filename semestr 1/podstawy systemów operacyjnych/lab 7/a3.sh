#!/bin/bash
funkcja(){
    echo -n "$1 "
    if [ $1 != 10 ]; then
        funkcja $[$1 + 1]
    fi
}
funkcja 1
echo