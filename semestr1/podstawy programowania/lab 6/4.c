#include <stdio.h>

void sort(int *tab, int size);

int main(){
    int tab[10] = {54, 32, 54, 21, 86, 34, 97, 54, 76, 23};
    // deklaracja tablicy
    sort(tab, 10);
    // wywołuję funkcję sort
    for(int i=0; i<10; i++) printf("%d ", tab[i]);
    // wypisuję tablicę
    return 0;
}
void sort(int *tab, int size){
    int change, swap;
    // change - wzkazuje czy w danej iteracji zostało coś zmienione
    // swap - zmienna pomocnicza do zamieniania elementów
    for(int i=0; i<size-1; i++){
        change=0;
        // change ustawiamy na brak elementów
        for(int j=0; j<size-1-i; j++){
            if(tab[j+1] < tab[j]){
                // jeśli obecny element jest większy od poprzedniego
                swap = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = swap;
                // zamieniamy elementy miejscami
                change=1;
                // change zmienieamy na prawdę
            }
        }
        if(!change) return;
        // jeśli w danej iteracji nie było zmiany kończę działanie funkcji
    }
}