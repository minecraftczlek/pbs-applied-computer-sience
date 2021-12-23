#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool znajduje_sie_w(unsigned char c, unsigned char *pointer);

int main(){
    unsigned char string[99], c;

    puts("wprowadz lancuch znakowy: ");
    fgets(string, 99, stdin);

    for(int i=0; i<strlen(string); i++){
        printf("Podaj znak do sprawdzenia: ");
        c = getchar();
        if(c == '\n') c = getchar();
        if(znajduje_sie_w(c, string)) printf("znak \"%c\" znajduje się w lancuchu\n", c);
        else printf("znak \"%c\" nie znajduje się w lancuchu\n", c);
    }
    
    return 0;
}

bool znajduje_sie_w(unsigned char c, unsigned char *pointer){
    for(int i=0; i<strlen(pointer); i++) if(pointer[i]==c) return true;
    return false;
}