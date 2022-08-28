#include <stdio.h>

double min(double a, double b){
    if(a<b) return a;
    else return b; 
}

int main(){
    printf("%f", min(2.64, 6.45));
    return 0;
}