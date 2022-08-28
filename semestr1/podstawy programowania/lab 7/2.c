#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool znajduje_sie_w(unsigned char c, unsigned char *pointer);

int main(){
    unsigned char string[99], c;

    puts("wprowadz lancuch znakowy: ");
    fgets(string, 99, stdin);
    // pobieranie łańcucha

    for(int i=0; i<(strlen(string)-1); i++){
        fflush(stdin); // czyszczenie buforu
        printf("Podaj znak do sprawdzenia: ");
        c = getchar();
        // pobieranie znaku do sprawdzenia
        if(znajduje_sie_w(c, string)) printf("znak \"%c\" znajduje się w lancuchu\n", c);
        else printf("znak \"%c\" nie znajduje się w lancuchu\n", c);
        // sprawdzanie czy dany znak znajduje się w łańcuchu
    }
    
    return 0;
}

bool znajduje_sie_w(unsigned char c, unsigned char *pointer){
    for(int i=0; i<strlen(pointer); i++) if(pointer[i]==c) return true;
    return false;
}