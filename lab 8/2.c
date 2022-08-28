#include <stdio.h>
#include <math.h>

struct kolo{
    int numer;
    char nazwa[10];
    float x, y, r1;
};

int main(){
    
    struct kolo k[3] = {
        { 1, "kolo1", 3, 6, 4 },
        { 2, "kolo2", 3.54, 7.34, 5.3 },
        { 3, "kolo3", 5.43, 6.32, 6.23 },
    };
    float x,y;

    printf("Podaj x: ");
    scanf("%f", &x);
    printf("Podaj y: ");
    scanf("%f", &y);

    for(int i=0; i<3; i++){
        if(sqrt(pow(x-k[i].x, 2) + pow(y-k[i].y, 2)) <= k[i].r1) printf("punkt nalezy do kola nr: %d\n", k[i].numer);
        else printf("punkt nie nalezy do kola nr: %d\n", k[i].numer);
    }
    
    // for(int i=0; i<3; i++){
    //     printf("Podaj numer: ");
    //     scanf("%d", &k[i].numer);
    //     printf("Podaj nazwe: ");
    //     scanf("%s", &k[i].nazwa[0]);
    //     printf("Podaj x: ");
    //     scanf("%f", &k[i].x);
    //     printf("Podaj y: ");
    //     scanf("%f", &k[i].y);
    //     printf("Podaj r: ");
    //     scanf("%f", &k[i].r1);
    // }

    
    
    return 0;
}