#include <stdio.h>
#include <math.h>
// math przyda się do obliczania potęg

int get(){
    printf("Podaj liczbe calkowita dziesietna dodadnia: ");
    unsigned int x;
    scanf("%d", &x);
    // pobieram liczbę od użytkownika
    return x;
}

void convert(int x){
    if(x==0){
        printf("0");
        return;
    }
    else if(x==1){
        printf("1");
        return;
    }
    // dla 0 i 1 usztawiam warotści na sztywno
    int max=0, q=0; //max-maksymalny wykładnik, q-aktualnie sprawdzany wykładnik
    while(!max){
        int w = pow(2, q);
        if((x / w) >= 2) q++;
        else{
            max = q;
            x -= w;    
            printf("1");
            // wypisuję pierwszy bit
        }
    }
    // obliczam maksymalną potęge

    for(int i=max-1; i>=0; i--){
        int w = pow(2, i);
        if(x > w){
            x -= w;
            printf("1");
        }else printf("0");
    }
    // obliczam pozostałe bity jeśli jakiś jest równy jeden to odejmuje jego wartość od x
}

int main(){
    convert(get());
    return 0;
}