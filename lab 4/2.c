#include <stdio.h>
#define rate 40

int main(){
    float hours = 40, brutto = 0, netto;
    // scanf("%d", &hours);

    brutto += (rate*40) + ((hours-40)*rate*1.5);

    netto = brutto;

    printf("Wynagrodzenie brutto: %1.2fzl,\n", brutto);

    if(brutto<=1200){
        netto -= brutto*0.15;
        brutto = 0;
    }else{
        netto -= 1200*0.15;
        brutto -= 1200;

        if(brutto < 600){
            netto -= brutto*0.2;
            brutto = 0;
        }
        else{
            netto -= 600*0.2;
            brutto -= 600;
            netto -= brutto * 0.25; 
        }
    }

    printf("kwota netto wynosi: %1.2fzl\n",netto);

    return 0;
}