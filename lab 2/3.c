#include <stdio.h>
    
int main(int argc, char *argv[]){
    int y;
    scanf("%d", &y);

    if(y<0) y = -y;
    else y = y;
    printf("liczba bezwgledna: %d", y);


    return 0;
}