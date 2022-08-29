#include <stdio.h>

int main(){
    int tab[3][3];
    // deklaracja tablicy
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) scanf("%d", &tab[i][j]);
    // zapełnianie tablicy
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) printf("%d\t", tab[i][j]);
        printf("\n");
    }
    // wypisywanie tablicy
    return 0;
}