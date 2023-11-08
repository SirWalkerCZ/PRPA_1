#include <stdio.h>

typedef struct 
{
    float re, im;
} komplex;

void tisk(komplex x){printf("Real:%.2f\nImaginary: %+.2f\n", x.re, x.im);}

int main(){

    //typdef nástroj pro vytvoření aliasu datového typu
    typedef int cislo;

    //zavedl jsem novy datovy typ cislo
    cislo a = 10;

    printf("a = %i\n", a);

    komplex c1, c2;
    c1.re = 3.14;
    c2.im = -5.5;

    c2 = (komplex){4.4, 5.5};
    c1 = (komplex){.im = 7.7, .re = 8.8};

    tisk(c1);
    tisk(c2);

    return 0;
}