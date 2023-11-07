#include <stdio.h>

int main(void){
    int a = 10, b = 3;
    float c;
    c = a / b;
    printf("a / b = %f\n", c);
    c = (float)(a/b);
    printf("(float)(a / b) = %f\n", c);
    c = (float)a/b;
    printf("(float)a / b = %.10f\n", c);
    double d = (double)a/b;
    printf("(double)(a / b) = %.10f\n", d);
    float e = 3.1415678;
    //zkraceni poctu desetiných míst
    float f = ((int)(e * 1000))/1000.F;
    printf("Oriznute cislo: %.3f\n", f);

    return 0;
}