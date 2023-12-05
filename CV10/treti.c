#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[100];
    char * slovnik[10];
    int s = 0; //pozice ve slovniku
    while (scanf("%s", buffer)!=EOF)
    {
        printf("%s\n", buffer);
        char * tmp = malloc(30);
        strcpy(tmp, buffer);
        slovnik[s++]= tmp; //tohle je hustej způsob jak něco číst   
    }

    printf("\nSlovník:\n");
    for (int i = 0; i < s; i++)
    {
        printf("%s\n", slovnik[i]);
        free(slovnik[i]);
    }
    
    return 0;
}