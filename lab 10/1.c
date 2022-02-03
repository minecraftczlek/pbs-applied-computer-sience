#include <stdio.h>

int main(){
    int x;
    printf("podaj x: ");
    scanf("%d", &x);

    if((x&16)) printf("piaty bit ma wartosc 1\n");
    else printf("piaty bit nie ma wartosci 1\n");

    if((x&64)) printf("Osmy bit ma wartosc 1\n");
    else printf("osmy bit nie ma wartosci 1\n");
    
    
    return 0;
}