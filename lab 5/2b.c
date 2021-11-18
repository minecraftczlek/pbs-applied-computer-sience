#include <stdio.h>
#define xint unsigned long long int
// definiuje słowo kluczowe xint

int silnia(xint n){
    if(n == 1) return 1;
    // jeśli n==1 to po prostu zwracam 1
    return silnia(n-1) * n;
    // wywołuje rekurencyjnie funkcje i mnoże wynik * n
}

int main(){  
    printf("%d", silnia(7)); 
    // wywołujemu funkcję silnia i wypisujemy jej wynik  
    return 0;
}