#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, suma = 0;
    
    printf("podaj ilosc liczb:");
    scanf("%d", &n);
    

    int *wsk = malloc(n*sizeof(int));
    if(!wsk){
        printf("pamiec nie zostala przydzielona");
        return 0;
    }

    for(int i=0; i<n; i++){
        printf("Podaj %d. liczve: ", i+1);
        scanf("%d", &wsk[i]);
    }

    for(int i=0; i<n; i++)suma += wsk[i];

    printf("suma wnosi: %d", suma);
}