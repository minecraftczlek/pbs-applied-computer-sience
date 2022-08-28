#include <stdio.h>

typedef unsigned long long int xint;
// definiuje słowo kluczowe xint

xint main(){  
    xint result=1, n=7;
    // wynik na początku jest równy 1
    for(size_t i=2; i<=n; i++) result *= i;
    // zaczynam pętle od 2 do n i mnoże z każdą iteracją wynik przez i
    printf("%d", result);
    
    return 0;
}