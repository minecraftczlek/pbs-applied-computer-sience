#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, suma = 0;
    
    printf("podaj ilosc liczb: ");
    scanf("%d", &n);
    // pobieranie ilości liczb
    

    int *wsk = malloc(n*sizeof(int));
    // przydzielanie pamięci
    if(!wsk){
        printf("pamiec nie zostala przydzielona");
        return 0;
    }
    // wyświetlanie błędu w przypadku niepowodzenia przydzielania

    for(int i=0; i<n; i++){
        printf("Podaj %d. liczbe: ", i+1);
        scanf("%d", &wsk[i]);
    }
    // zapełanianie tablicy

    for(int i=0; i<n; i++)suma += wsk[i];
    // liczenie sumy

    free(wsk);
    // zwalnienie pamięci

    printf("suma wnosi: %d", suma);
    // wyświetlanie sumy
}