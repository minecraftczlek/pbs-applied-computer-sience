#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lz =  5; // liczba zawodników

    srand(time(NULL));
    printf("Podaj liczbe zawodników:\n");
    scanf("%d", &lz);
    printf("Liczba zawodników to: %d\n\n", lz);

        for (int loc = 1; loc <= lz; loc++)
        {
            int ss = 0;

            printf("Sędzia pierwszy ocenia.\n");
            ss += rand() % 2;

            printf("Sędzia drugi ocenia.\n");
            ss += rand() % 2;

            printf("Sędzia trzeci ocenia.\n");
            ss += rand() % 2;


            if (ss>= 2) printf("Sedzia zakfalifikowal zawodnika numer: %d, punkty: %d\n\n", loc, ss);
            else printf("Sedzia nie zakfalifikowal zawodnika: %d nie przechodzi dalej, punkty: %d.\n\n", loc, ss);
        }


    getchar();
    getchar();

    return 0;
}

