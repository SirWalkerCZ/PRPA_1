/*
Program ze standardního vstupu načte symboly, které se mají kódovat.
Kódují se symboly, které patří do množiny velkých písmen ('A' - 'Z').
Kódování se řídí pravidly popsanými v sekci Implementace.
Pokud se na vstupu objeví symbol, který nepatří do této množiny, vypíše program na standardní chybový výstup zprávu: 
“Error: Neplatny symbol!\n” a program ukončete s návratovou hodnotou 100. Viz Příklad 4.
Běh programu je v tomto případě okamžitě ukončen a výstupní soubor není ukončen znakem 0x0A.
Pokud se podaří zakódovat všechny vstupní symboly, vypíše se na standardní výstup zakódovaná sekvence a na
standardní chybový výstup se vypíše dosažený kompresní poměr. Viz Příklad 1.
Vstupní i výstupní soubor jsou ukončeny znakem 0x0A, který se při výpočtu kompresního poměru nezapočítává.
*/

#include <stdio.h>

int main(void){
    char symb, lastSymb;
    int symbolCount = 0;
    while (scanf("%c", &symb)<0)
    {
        if (symb >= "A"&& symb <="Z")
        {
            if (symb==lastSymb)
            {
                symbolCount++;               
            }
            else{
                while (symbolCount > 255) //if the symbolCount is bigger then 255, write that and decrease it
                {
                    symbolCount = symbolCount - 255;
                    print("%c%i", lastSymb, 255);
                }
                if (symbolCount==1) //if its just one symbol, write that
                {
                    printf("%c", lastSymb);
                    break;
                }                
                //if 2 symbols = AA, else A+count
                (symbolCount == 2) ? print("%c%c", lastSymb, lastSymb) : printf("%c%i", lastSymb, symbolCount);
                symbolCount = 1;
            }
            lastSymb = symb;
        }
        else{
            ("Error: Neplatny symbol!\n");
        }
        
    }
    
}