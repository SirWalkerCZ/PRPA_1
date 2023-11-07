#include <stdio.h>
int main(void){
    int num1, num2;
    scanf("%i%i", &num1, &num2);
    if (num1 < -10000 || num1 > 10000){
        printf("Vstup je mimo interval!\n");
        return 0;
    }
    if (num2 < -10000 || num2 > 10000){
        printf("Vstup je mimo interval!\n");
        return 0;
    }
    printf("Desitkova soustava: %i %i\n",num1,num2);
    printf("Sestnactkova soustava: %x %x\n", num1,num2);
    printf("Soucet: %i + %i = %i\n", num1, num2, num1+num2);
    printf("Rozdil: %i - %i = %i\n", num1, num2, num1-num2);
    printf("Soucin: %i * %i = %i\n", num1, num2, num1*num2);
    if (num2 == 0)
    {
        printf("Nedefinovany vysledek!\n");
    }
    else{
        printf("Podil: %i / %i = %i\n", num1, num2, num1/num2);
    }
    printf("Prumer: %0.1f\n", (float)(num1 + num2)/2);
    return 0;
}

