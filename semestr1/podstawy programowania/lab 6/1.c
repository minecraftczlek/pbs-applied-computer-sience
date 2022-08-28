#include <stdio.h>

int main(){
    int table[5];
    // deklaracja tablicy
    for(int i=0; i<5; i++) scanf("%d", &table[i]);
    // uzupełnianie tablicy
    for(int i=4; i>=0; i--) printf("%d ", table[i]);
    // wypisywanie tablicy w odwrotnej kolejności
    return 0;
    // zmiana
}