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



int main(int argc, char *argv[]) {

    uzel a;
    a.data = 10;
    a.adresa = NULL;

    uzel b;
    b.data = 20;
    b.adresa = &a;

    uzel c;
    c.data = 30;
    c.adresa = &b;
    printf("c.data = %i\n", c.data);
    printf("b.data = %i\n", (*c.adresa).data);
    printf("a.data = %i\n", ((*c.adresa).adresa)->data);

    //pomocí pomocné promenne
    uzel *t;
    t = &c;
    printf("c.data = %i\n", t->data);
    t = t->adresa;
    printf("b.data = %i\n", t->data);
    return 0;
}