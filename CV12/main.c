#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// funkce pro odstranění interpunkce
void interpunkce(char * slovo)
{
    int posledni = strlen(slovo);
    //printf("%c\n", slovo[posledni-1]);
    if (slovo[posledni-1]=='.'||slovo[posledni-1]==',')
    {
        slovo[posledni-1]='\0';
    }
    
}

void bubble(char ** slovnik, int velikost){
    for (int i = 0; i < velikost; i++)
    {
        for (int j = 0; j < velikost; j++)
        {
            if (strcmp(slovnik[j], slovnik[j+1])<0)
            {
                char * tmp=slovnik[j];
                slovnik[j]=slovnik[j+1];
                slovnik[j+1]= tmp;
            }
            
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    // pole ukazetele na retezce (tj. ukazetele)
    // pri malloc dostanu ukazatel na pole ukazatelu
    char **slovnik = malloc(sizeof(char *));
    int index = 0;
    char buffer[100];

    while (scanf("%s", buffer) != EOF)
    {
        // printf("%s\n",buffer);
        // vytvořím záznam v dynamické paměti
        char *tmp = malloc(strlen(buffer) + 1);
        strcpy(tmp, buffer);
        slovnik[index++] = tmp;
        // realokace pole -> priprava nového prvku
        slovnik = realloc(slovnik, sizeof(char *) * (index + 1));
    }
    bubble(*slovnik, index);
    for (int i = 0; i < index; i++)
    {
        interpunkce(slovnik[i]);


        printf("%s\n", slovnik[i]);
    }

    return 0;
}
