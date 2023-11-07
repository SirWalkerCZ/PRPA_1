#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    int numA, numB, numC, numDis;
    scanf("%i%i%i",&numA, &numB, &numC);
    numDis = (numB*numB)-4*numA*numC;
    if (abs(numDis) > 999){
        printf("Diskriminant mimo povoleny interval!\n");
        return 0;
    }
    printf("+-----+-----+-----+-----+\n|%4i |%4i |%4i |%4i |\n+-----+-----+-----+-----+\n", numA, numB, numC, numDis);
    if (numDis < 0){
        printf("| Dva imaginarni koreny |\n");
    }
    if (numDis == 0){
        printf("|           Jeden koren |\n");
    }
    if (numDis > 0){
        printf("|     Dva realne koreny |\n");
    }
    printf("+-----------------------+\n");
    return 0;
}