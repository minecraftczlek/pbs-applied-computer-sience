#include <stdio.h>
#include <ctype.h>

int main(){
    int words = 0, chars = 0;
    char c;

    while (c != '\n'){
        c = getchar();
        if(isspace(c)) words++;
        else chars++;
    }
    
    printf("liczba slow: %d,\nliczba znakow: %d\n", words, chars);
    return 0;
}