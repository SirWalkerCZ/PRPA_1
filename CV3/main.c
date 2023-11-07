#include <stdio.h>

int main(){

    int a,b,c, read;
    read = scanf("%i%i%i",&a,&b,&c);
    if (read !=3)
    {
        printf("Spatny pocet argumentu, ukoncuji program");
        return 1;
    }
    
    printf("Strany trojúhelníku a=%i, b=%i, c=%i\n", a, b,c);
    if (a+b>c &&(a+c)>b&&(b+c)>a)
    {
        printf("Trojúhelník lze sestrojit\n");
    }
    else{
        printf("Trojúhelník nelze sestrojit\n");
    }
    
    return 0;
}