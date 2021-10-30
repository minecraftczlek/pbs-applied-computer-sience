#include <stdio.h>
    
int main(int argc, char *argv[]){

    int x[4];
    for(int i=0; i<4; i++){
        scanf("%f", &x[i]);
    }

    int wieksze = 0, mniejsze = 0;

    for(int i=0; i<4; i++){
        if(x[i]>0) wieksze++;
        else if(x[i]<0) mniejsze++;
    }

    printf("wieksze: %d, mniejsze: %d\n", wieksze, mniejsze);

    if(wieksze>mniejsze) printf("wiecej jest liczb wiekszych od zera");
    else if(wieksze<mniejsze) printf("wiecej jest liczb mniejszych od zera");
    else if(wieksze==mniejsze) printf("liczb mniejszych i wiekszych od zera jest tyle samo");

    return 0;
}