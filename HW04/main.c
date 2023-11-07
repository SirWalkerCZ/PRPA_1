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
    char symb;
    while (scanf("%c", &symb)<0)
    {
        if (symb >= "A"&& symb <="Z")
        {
            /* code */
        }
        else{
            ("Error: Neplatny symbol!\n");
        }
        
    }
    
}