#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char * r1 = "ahoj";
    char r2[] = "ahoj";

    printf("%li\n", strlen(r1));
    printf("%li\n", strlen(r2));

    int delka = strlen(r1);
    for (int i = 0; i < delka; i++)
    {
        //FRAJERSKY ZMĚNÍM BIT ABY TO TISKLO VELKÁ PÍSMENA AAAAAAAAAA
        printf("%c", r1[i] & ~(1 << 5));
    }
    printf("\n");   
    if (strcmp(r1, r2))
    {
        printf("Řetězce jsou stejné\n");
    }
    else{
        printf("nejsou\n");
    }
    
    return 0;

}