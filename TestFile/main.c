#include <stdio.h>

int main(){


    int i[2] = {1, 2}; 
    printf("%i\n", i[4]);
    *(int*)0 = 0;
    return 0;

}