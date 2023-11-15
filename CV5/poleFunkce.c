#include <stdio.h>
int velikost;

void tisk(int * pole, int velikost){
    for (size_t i = 0; i < velikost; i++)
    {
        printf("pole[%i]\n", pole[i]);
    }    
}

void vytvor(int *pole, int velikost, int hodnota){
    for (int i = 0; i < velikost; i++)
    {
        pole[i] = hodnota;
    }    
}

int main(){
    int pole[] = {2,3,4,5,6,7};
    int * p = pole;
    printf("adresa pole: %p\n", pole);

    velikost = sizeof(pole)/sizeof(int);
    tisk(pole, velikost);

    int pole1[10];
    vytvor(pole1, 10, 10);
    tisk(pole1, sizeof(pole1)/sizeof(int));

    return 0;
}