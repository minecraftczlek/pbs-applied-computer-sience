#include <stdio.h>
    
int main(){
    int x;
    scanf("%d", &x);

    if(x<0) x = -x;
    printf("liczba bezwgledna: %d", x);

    return 0;
}