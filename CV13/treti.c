#include <stdio.h>
#include <stdlib.h>

//práce s fragmentovano pamětí, řazení adres ať odkazují na sebe

    /*
    seznam je tvořen uzly
    *užitečná data
    *adresa následujícího (případně předchozího) prvku
    
    
    */

typedef struct kozelUzel
{
    int data;
    struct kozelUzel * adresa;
} uzel;
uzel * novy(int data){
uzel * t = malloc(sizeof(uzel));
t->data =data;
t->adresa = NULL;
return t;
}


int main(){
    uzel * seznam = novy(0);

    for (size_t i = 10; i < 40; i++)
    {
        uzel * x = novy(i);
    }
    
}