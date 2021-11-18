#include <stdio.h>
#include <math.h>

double get(); // pobieranie danych od użytkownika
double toRadians(double degree);  // konwersja z stopni na radiany

int main(){
    double x = toRadians(get());
    // pobieram dane od użytkownika i konwertuje na radiany
    printf("sinus: %f, \ncosinus: %f, \ntangens: %f", sin(x), cos(x), tan(x));
    // wypisuje wyniki wykorzystując wbudowane funkcje w math.h
    return 0;
}

double get(){
    printf("Podaj wartosc kata alfa w stopniach: ");
    double x;
    scanf("%lf", &x);
    // pobieram liczbę od użytkownika
    return x;
}

double toRadians(double degree){
    return degree * ( M_PI / 180.0 );
    // M_PI stała w math.h oznaczająca stałą PI
}
