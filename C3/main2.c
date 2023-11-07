#include <stdio.h>

int main(void){

    int var1, var2;
    int val = scanf("%i%i", &var1, &var2);

      printf("var = %i\nvar2 = %i\nr = %i\n", var1, var2, val);
    
    return val;
}