#include <stdio.h>
#include <string.h>

void skracaj(unsigned char *pointer, int size);

int main(){
    unsigned char string[99], c;
    int size;

    puts("wprowadz lancuch znakowy: ");
    fgets(string, 99, stdin);
    puts("pobrany lancuch:");
    puts(string);
    printf("rozmiar lancucha: %d\n", strlen(string) - 1);

    printf("Podaj do jakiej wielkosci ma byc skrocony lancuch: ");
    scanf("%d", &size);

    skracaj(string, size);

    puts("lancuch wynikowy:");
    puts(string);
    printf("rozmiar lancucha: %d\n", strlen(string));

    return 0;
}

void skracaj(unsigned char *pointer, int size){
    pointer[size] = 0;
}