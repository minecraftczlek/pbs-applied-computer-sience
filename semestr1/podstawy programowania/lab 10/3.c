#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc<4){
        printf("podaj wymagane argumenty");
        return 0;
    }

    char *p;
    int x = strtol(argv[1], &p, 8),
    y = strtol(argv[3], &p, 8);
    char operator = argv[2][0];

    if(operator='&')printf("%d", x&y);
    if(operator='|')printf("%d", x|y);
    if(operator='^')printf("%d", x^y);

    // printf("%d %c %d", x, operator, y);
    return 0;
}