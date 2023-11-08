#include <stdio.h>
struct student
{
    int vyska;
    float vaha;
    char zapocet;
};

int main(){
    struct student pepa;
    pepa.vaha = 200;
    pepa.vyska = 50;
    pepa.zapocet = 'Y';

    struct student trida[10];
    trida[0] = pepa;    
    printf("pepa: %i %.2f %c\n", trida[0].vyska , trida[0].vaha , trida[0].zapocet);
    return 0;
}