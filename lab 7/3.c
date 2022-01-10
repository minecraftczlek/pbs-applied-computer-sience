#include <stdio.h>
#include <string.h>

void sklej(unsigned char *A, unsigned char *B);

int main(){
    unsigned char A[200], B[100];

    puts("wprowadz lancuch znakowy A: ");
    fgets(A, 100, stdin);
    puts("wprowadz lancuch znakowy B: ");
    fgets(B, 100, stdin);
    // pobieram łańcuchy
    
    sklej(A,B);

    puts(A);
    
    return 0;
}

void sklej(unsigned char *A, unsigned char *B){
    int size = strlen(A) - 1;
    for(int i=0; i<strlen(B)-1; i++) A[size + i] = B[i];
}