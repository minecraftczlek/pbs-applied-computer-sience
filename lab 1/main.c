#include <stdio.h> 

int main(){ 
   int unsigned liczba1, liczba2, liczba3; 
   float srednia; 

   printf("Srednia arytmetyczna z 3 liczb.\n Podaj 3 liczby\n"); 

   scanf("%d", &liczba1); 
   scanf("%d", &liczba2); 
   scanf("%d", &liczba3);

   srednia = ((float)liczba1+liczba2+liczba3)/3; /*przykład rzutowania zmiennych */

   printf("%f",srednia);

   printf("Srednia arytmetyczna z liczb %d,%d,%d wynosi %.3f", liczba1, liczba2, liczba3, srednia);
   /*funkcja printf wyświetlająca wynik średniej z 3 miejscami po przecinku, oraz wyświetlająca
   podane liczby */
   getchar(); /* funkcja getchar () wczytuje znak z wejścia zmuszając program do oczekiwania na
   wprowadzenie danych */
   return 0; 
}