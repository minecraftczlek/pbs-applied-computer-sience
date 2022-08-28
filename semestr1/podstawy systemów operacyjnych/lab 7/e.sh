#!/bin/bash
if [ $2 ]; then
    group=$2
else
    group=$1
fi
if [ $3 ]; then
    useradd -g $group -s /usr/bin/$3 $1
else
    useradd -g $group $1
fi