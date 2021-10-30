#include <stdio.h>
#include <math.h>
    
int main(int argc, char *argv[]){
    char wybor = argv[1][0];

    switch (wybor){
    case 'k':{
        float a;
        printf("Podaj bok kwadratu: ");
        scanf("%f", &a);
        printf("Pole kwadratu wynosi: %f", pow(a, 2));
        break;  
    } 
    case 'p':{
        float a, b;
        printf("Podaj boki prostokata: ");
        scanf("%f", &a);
        scanf("%f", &b);
        printf("Pole kwadratu wynosi: %f", a*b);
        break;  
    }
    case 't':{
        float a, h;
        printf("Podaj bok i wysokosc trojkata: ");
        scanf("%f", &a);
        scanf("%f", &h);
        printf("Pole trojkata wynosi: %f", a*h/2);
        break;  
    }
    default:
        printf("Podaj porwany argument k-kwadrat, p-prostokat, t-trojkat");
        break;
    }
    return 0;
}