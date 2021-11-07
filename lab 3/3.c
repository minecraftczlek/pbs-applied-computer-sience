#include <stdio.h>
    
int main(int argc, char *argv[]){
    for(int i = 2; i <= (255/16); i++){
        for(int j = (i*16+1); j < (i*16+16); j++) printf("%c ", (char)j);
        printf("\n");
    }


    return 0;
}