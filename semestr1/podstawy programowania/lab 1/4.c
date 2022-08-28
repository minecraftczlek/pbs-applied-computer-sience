#include <stdio.h>

int main(){

    int rok;
    printf("podaj wiek: ");
    scanf("%d", &rok);

    printf("twoj wiek w sekundach wynosi: %e", rok * 3.156E7);

    return 0;
}