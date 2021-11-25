#include <stdio.h>

typedef unsigned long long int xint;
// definiuje słowo kluczowe xint

xint silnia(xint n){
    if(n == 1 || n == 0) return 1;
    // jeśli n==1 to po prostu zwracam 1
    return silnia(n-1) * n;
    // wywołuje rekurencyjnie funkcje i mnoże wynik * n
}

int main(){  
    printf("%d", silnia(7)); 
    // wywołujemu funkcję silnia i wypisujemy jej wynik  
    return 0;
}