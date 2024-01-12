#include <stdio.h>
#include <stdlib.h>

//help na domácí úkoly

typedef struct {
    int velikost;
    int * data;
} jednorozmernePole;


void tisk(int cislo, int x[][cislo]){
printf("Jsem ve funkci\n");
} //můžu přidat druhý číslo do první []

void napln(int ** x, int H, int W){
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            x[j][i] = 33;
        }
        
    }
    
}

int main(int argc, char *argv[]) {
    int a[10][10]; 
    //jak procpat dvourozmrné pole jako arg funkce
    tisk(a, 10);

    int ** b = malloc(2*sizeof(int *));
    b[0] = malloc(2*sizeof(int));
    b[1] = malloc(2*sizeof(int));


    napln(b, 2, 2);

    printf("B1,1= %i\n", b[1][1]);

    jednorozmernePole c;
    c.velikost = 10;
    c.data = malloc(c.velikost*(sizeof(int)));
    //přístup
    c.data[0] = 10;

    jednorozmernePole *d = malloc(sizeof(jednorozmernePole));
    d->velikost = 10;
    (*d).data = malloc(d->velikost*sizeof(int));

    return 0;
}