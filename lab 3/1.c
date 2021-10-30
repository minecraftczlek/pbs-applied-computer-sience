#include <stdio.h>
    
int main(int argc, char *argv[]){

    unsigned int x=5, y=1;
    // scanf("%d", &x);
    for(int i=1; i<=x; i++){
        for(int j=0; j<i; j++){
            printf("%d ", y);
            y++;
        }
        printf("\n");
    }

    return 0;
}