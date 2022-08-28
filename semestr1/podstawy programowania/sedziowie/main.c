#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    int players = 10;
    printf("Podaj liczbe zawodników: ");
    scanf("%d", &players);
    srand(time(NULL));

    for (size_t i = 1  ; i <= players; i++){
        int points = 0;

        for (size_t j = 0; j < 3; j++) points += rand() % 2;

        if(points >= 2) printf("Gracz nr:%d przeszedl do następnej rundy zdobywajac %d punkty.\n", i, points);
        else printf("Gracz nr:%d nie przeszdl do nastepnej rundy, zdobył nastepujaca ilosc punktow: %d.\n", i, points);
    }
    
    return 0;
}

