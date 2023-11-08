#include <stdio.h>

int main(){
    int N;
    // prvni cislo v posloupnosti je delka datové řady
    scanf("%i\n", &N);
    int pole1[N];
    for (size_t i = 0; i < N; i++)
    {
        scanf("%i\n", &pole1[i]);
    }
    printf("Pole1:\n");
    for (size_t i = 0; i < N; i++)
    {
        printf("%i\n", pole1[i]);
    }
    int max = __INT32_MAX__;
    int min = - __INT32_MAX__;
    printf("Min: %i\nMax: %i", min, max);
    return 0;
}