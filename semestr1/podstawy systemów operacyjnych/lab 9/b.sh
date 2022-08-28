#!/bin/bash
function funkcja(){
    for (( i=1;i<=$#;i++)); do 
        echo $1
    done
}
echo "lista zalogowanych użytkowników"
funkcja `who | awk '{print $1}'`
