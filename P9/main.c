#include <stdio.h>
#include <stdlib.h>


void mkField(int sizeF, int * field){
    int pole[sizeF];
    //return pole;
}


//alokace paměti
int main(int argc, char *argv[]){


    int d[10];


    //vytvořil jsem si pole charu velikosti deset
    char * a = malloc(10);
    //
    char * b = calloc(10, sizeof(char));


    a[0] = 'a';
    a[1] = '\0';

    free(a); //dealokuje pole



}
