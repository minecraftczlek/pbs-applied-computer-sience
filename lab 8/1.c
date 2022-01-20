#include <stdio.h>

struct zbiorka{
    char imie[10];
    char grupa[15];
    float kwota;
};

int main(){
    struct zbiorka darczyncy[30];
    int ilosc;

    printf("Podaj ilosc darczyncow: ");
    scanf("%d", &ilosc);

    for(int i=0; i<ilosc; i++){
        printf("Podaj Imie: ");
        scanf("%s", &darczyncy[i].imie[0]);
        printf("Podaj nazwe grupy: ");
        scanf("%s", &darczyncy[i].grupa[0]);
        printf("Podaj kwote: ");
        scanf("%f", &darczyncy[i].kwota);
    }

    return 0;
}