#include <stdio.h>
    
int main(int argc, char *argv[]){
    int N=10, i=1;
    printf("Wpisz wartość N: ");
    scanf("%d", &N);

    printf("Liczby nieparzyste od 1 do %d: ", N);
    while(i<=N){
        printf("%d ", i);
        i+=2;
    }
    return 0;
}