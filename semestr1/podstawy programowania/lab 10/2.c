#include <stdio.h>

struct data{
    unsigned int dzien : 5;
    unsigned int miesiac : 4;
    unsigned int godzina : 5;
    unsigned int minuta : 6;
};


int main(){
    
    struct  data dzien = {28, 9, 21, 56};

    printf("%d/%d // %d:%d", dzien.dzien, dzien.miesiac, dzien.godzina, dzien.minuta);
    
    
    return 0;
}