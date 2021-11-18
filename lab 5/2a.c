#include <stdio.h>
#define xint unsigned long long int
// definiuje słowo kluczowe xint

int main(){  
    xint result=1, n=7;
    // wynik na początku jest równy 1
    for(int i=2; i<=n; i++) result *= i;
    // zaczynam pętle od 2 do n i mnoże z każdą iteracją wynik przez i
    printf("%d", result);
    
    return 0;
}