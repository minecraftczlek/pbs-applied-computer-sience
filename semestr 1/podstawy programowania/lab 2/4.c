#include <stdio.h>
    
int main(int argc, char *argv[]){
    char operacja = argv[1][0];
    float x, y, wynik;
    scanf("%f", &x);
    scanf("%f", &y);

    switch (operacja){
    case '+':
        wynik = x + y;
        break;
    case '-':
        wynik = x - y;
        break;
    case '/':
        wynik = x / y;
        break;
    case '*':
        wynik = x * y;
        break;
    default:
        printf("Podaj poprawny operator (+-/*)");
        return 0;
        break;
    }

    printf("wy4 nik: %f", wynik);

    return 0;
}