#include <stdio.h>

int main(){
    int N;
    // prvni cislo v posloupnosti je delka datové řady
    scanf("%i\n", &N);
    int pole1[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%i\n", &pole1[i]);
    }
    printf("Pole1:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", pole1[i]);
    }
    printf("\n");

    for (int z = 0; z < 10; z++)
    {
        for (int i = 0; i < N-1; i++)
        {
            if (pole1[i]>pole1[i+1]) //prohod dvě hodnoty 
            {
                int t = pole1[i+1];
                pole1[i+1] =pole1[i];
                pole1[i]=t;
                /* pole1[i] = pole1[i+1]+pole1;
                pole1[i] = pole1[i+1] - pole1[i];
                pole1[i+1] = pole1[i+1] - pole1[i];*/
            }
            
        }
        printf("Pole1 po seřazení:\n");
        for (int i = 0; i < N; i++)
        {
            printf("%i ", pole1[i]);
        }
        printf("\n");   
    }
}