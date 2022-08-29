#include <stdio.h>

int main(){

    float wzrost, waga;

    printf("Podaj wzrost:");
    scanf("%f", &wzrost);
    printf("Podaj wage:");
    scanf("%f", &waga);

    float BMI = waga / ((wzrost/100) * (wzrost/100));

    printf("BMI wynosi: %f", BMI);

    return 0;
}