#include <stdio.h>
#include <stdlib.h>

// Na standardním vstupu očekávejte číslo, které reprezentuje délku zprávy, a dvě posloupnosti znaků (texty) na samostatných řádcích. První text je zakódovaná zpráva a druhý text je nespolehlivě odposlechnutý text.

// Pokud na prvním řádku není číslo nebo vstupní text neodpovídá abecedě [a-zA-Z] vypíše program na standardní chybový výstup “Error: Chybny vstup!” a skončí s návratovou hodnotou 100.
// Pokud je některý ze vstupních textů kratší, než uvádí číslo na prvním řádku souboru, program vypíše na stderr “Error: Chybna delka vstupu!” a skončí s návratovou hodnotou 101.
// Současný výskyt obou chyb není testován.
// Informace o chybě vypsaná na standardní chybový výstup není ukončena znakem konce řádku.

void shift(const char *src, char *dst, int offset);
 
int compare(const char *str1, const char *str2);

//10 neboli 0A
int lenght;
int main(){

    while(scanf("%i", &lenght)>0);
    if (lenght != (int)lenght) //nutno otestovat
    {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        return 101;
    }
    printf("%i\n", lenght);
    
    char text1[lenght];
    
    for (int i = 0; i < lenght; i++)
    {
        printf("%i", i);
        char temp;
        if (scanf("%c", &temp)==EOF)
        {
            fprintf(stderr, "Error: Chybna delka vstupu!");
            return 101;
        }
        
        if ((temp>= 'A' && temp <= 'Z') || (temp > 'a' && temp < 'z'))
        {
            text1[i] = temp;
        }
        else{
            fprintf(stderr, "Error: Chybny vstup!");
            return 100;
        }
        
    }
    
    
    printf("%s\n", text1);

    char* text2 = NULL;
    text2 = (char*) malloc(lenght * sizeof(char));
    if (text2 == NULL) //v případě že je pamět plná
    {
        printf("Alokace se nepodařila");
        return -1;
    }
    
    scanf("%s", text2);  
    printf("%s\n", text2);

    return 0;
}