#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumInt(int *tab);
float sumFloat(float *tab);
int minInt(int x, int y);
float minFloat(float x, float y);
int maxInt(int x, int y);
float maxFloat(float x, float y);

int main(){
    srand(time(NULL));
    int tab1[10], *wzk1 = &tab1[0];
    float tab2[10], *wzk2 = &tab2[0];
    // deklaracja tablic i wzkaźników

    for(int i=0; i<10; i++) tab1[i] = rand() % 101;
    // losowanie licz 0 - 100

    for(int i=0; i<10; i++) tab2[i] = rand() % 10001 * 0.0001;
    // losowanie liczb zmiennoprzecinkowych 0 - 1

    printf("suma int: %d\nsuma float: %lf\n", sumInt(tab1), sumFloat(tab2));
    // wyświetlanie sumy liczb

    printf("\n5 i 9 elementy tablicy:\nint - %d, %d, min - %d, max - %d\nfloat - %lf, %lf min - %lf, max - %lf", *(wzk1+4), *(wzk1+8), minInt(*(wzk1+4), *(wzk1+8)), maxInt(*(wzk1+4), *(wzk1+8)), *(wzk2+4), *(wzk2+9), minFloat(*(wzk2+4), *(wzk2+8)), maxFloat(*(wzk2+4), *(wzk2+8)));
    // wyświetlanie 5 i 9 elementu oraz liczbę  większ i mniejszą z nich
    
    return 0;
}

int sumInt(int *tab){
    int sum = 0;
    for(int i=0; i<10; i++) sum += tab[i];
    return sum;
}

float sumFloat(float *tab){
    float sum = 0;
    for(int i=0; i<10; i++) sum += tab[i];
    return sum;
}

int minInt(int x, int y){
    if(x < y) return x;
    return y;
}

float minFloat(float x, float y){
    if(x < y) return x;
    return y;
}

int maxInt(int x, int y){
    if(x > y) return x;
    return y;
}

float maxFloat(float x, float y){
    if(x > y) return x;
    return y;
}