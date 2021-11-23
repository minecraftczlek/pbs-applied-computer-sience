#include <stdio.h>

int get(){
    printf("Podaj liczbe calkowita dziesietna dodadnia: ");
    unsigned int x;
    scanf("%d", &x);
    // pobieram liczbę od użytkownika
    return x;
}

void decToBin(unsigned int x){
    short int tab[32], i;
    // tab przechowuje bity w odwrotnej kolejności, i iterator to pętli

    for(i=0; x>0; i++){
        // pętle wykonujemy do czasu aż x będzie większe od 0
        tab[i] = x%2;
        // do tablicy wpisujemy odpowiedni bit 0 lub 1
        x /= 2;
    }
    for(i-=1; i>=0; i--) printf("%d", tab[i]);
    // wypisujemy tablicę w odwrotnej kolejności
}

int main(){
    decToBin(get());
    return 0;
}