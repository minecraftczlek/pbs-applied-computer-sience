#include <stdio.h>

int main(){

    int x;
    printf("Podaj liczbe:");
    scanf("%d", &x);

    float f = (float)x;
    printf("format zmiennoprzecinkowy: %.1f, %.3f \n", f, f);

    if(x >=0 && x <=9) printf("format znakowy: %c", (char)x+48);

    return 0;
}
