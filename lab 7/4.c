#include <stdio.h>
#include <string.h>

void zlicz_wystapienia(char* tekst, int* litery, int *cyfry);

int main(){
    int cyfry[10], litery[26];
    for(int i=0; i<10; i++)cyfry[i]=0;
    for(int i=0; i<26; i++)litery[i]=0;
    char tekst[100];

    puts("wprowadz lancuch znakowy: ");
    fgets(tekst, 100, stdin);
    zlicz_wystapienia(tekst, litery, cyfry);
    
    while(1){
        fflush(stdin);
        printf("podaj litere lub cyfre: ");
        char c = getchar();
        if((c>=48)&&(c<=57)) printf("cyfra %c powtarza sie %d razy\n", c, cyfry[c-48]);
        if((c>=97)&&(c<=122)) printf("litera %c powtarza sie %d razy\n", c, litery[c-97]);
    }

    return 0;
}

void zlicz_wystapienia(char* tekst, int* litery, int *cyfry){
    for(int i=0; i<strlen(tekst); i++){
        if((tekst[i]>=48)&&(tekst[i]<=57)) cyfry[tekst[i]-48]++;
        else if((tekst[i]>=97)&&(tekst[i]<=122)) litery[tekst[i]-97]++;
    }
}