#include <stdlib.h>
#include <stdio.h>

void vypis_int(int * ptr, int delka){
    for (int* ptr_end= ptr+delka; ptr < ptr_end; ptr++)
    {
        printf("%i\t", *ptr);
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    int n = 5;
    int pole[n];
    for (int i = 0; i < n; i++)
    {
        pole[i]= i*i;
    }
    
    vypis_int(pole, n);
    return 0;
}