#include <stdio.h>
#include <math.h>

float get(); // pobieranie danych od użytkownika
float toRadians(float degree);  // konwersja z stopni na radiany

int main(){
    float x = toRadians(get());
    // pobieram dane od użytkownika i konwertuje na radiany
    printf("sinus: %f, \ncosinus: %f, \ntangens: %f", sin(x), cos(x), tan(x));
    // wypisuje wyniki wykorzystując wbudowane funkcje w math.h
    return 0;
}

float get(){
    printf("Podaj wartosc kata alfa w stopniach: ");
    float x;
    scanf("%f", &x);
    // pobieram liczbę od użytkownika
    return x;
}

float toRadians(float degree){
    return degree * ( M_PI / 180.0 );
    // M_PI stała w math.h oznaczająca stałą PI
}
