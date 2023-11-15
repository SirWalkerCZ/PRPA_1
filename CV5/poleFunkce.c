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

void minmax(int * pole, int * min, int * max, int velikost){
    for (int i = 0; i < velikost; i++)
    {
       if (pole[i]> *max)
       {
        *max=pole[i];
       }
       if (pole[i]< *min)
       {
        *min=pole[i];
       }       
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

    int min = __INT_MAX__, max = -__INT_MAX__;
    minmax(pole, &min, &max, sizeof(pole)/sizeof(int));
    printf("min: %i\nmax: %i", min, max);
    return 0;
}