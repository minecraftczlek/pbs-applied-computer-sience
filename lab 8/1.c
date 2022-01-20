#include <stdio.h>
#include <string.h>

struct zbiorka{
    char imie[10];
    char grupa[15];
    float kwota;
};
// definicja struktury

int main(){
    struct zbiorka darczyncy[30];
    // deklaracja tablicy struktur
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
        // pobieranie danych do zmiennych w strukturach
    }

    for(int i=0; i<ilosc; i++){
        printf("Imie: ");
        fputs(darczyncy[i].imie, stdout);
        printf(" , Grupa: ");
        fputs(darczyncy[i].grupa, stdout);
        printf(" ; kwota: %1.2f zl;\n", darczyncy[i].kwota);
        // wyświetlanie danych struktury
    }

    return 0;
}