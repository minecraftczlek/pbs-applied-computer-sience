#include <stdio.h>

int sum(int *tab){
    return *tab + *++tab;
    // zwracanie sumy pierwszego i następnego elementu
}

int main(){
    int tab[2];
    for(int i=0; i<2; i++) scanf("%d", &tab[i]);
    printf("%d", sum(tab));
    
    return 0;
}