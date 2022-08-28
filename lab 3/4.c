#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
int main(int argc, char *argv[]){
    int x=0;
    srand(time(NULL));
    while (x<6){
        x = rand() % 6 + 1;
        printf("%d ", x);
    }
    
    return 0;
}