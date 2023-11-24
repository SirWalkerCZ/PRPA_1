#include <stdio.h>

int main(int argc, char *argv[]) {
    int pole[4] = {[1]= 1, [3]= 3};

    int *pa = pole;

    printf("%i\n",  &pa+2);

    return 0;
}