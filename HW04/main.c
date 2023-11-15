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

void swiPrint(int repCount, char lastSymbol, int *out)
{
    while (repCount > 255)
    {
        *out += printf("%c255", lastSymbol);
        repCount = repCount - 255;
    }

    switch (repCount)
    {
    case 0:
        break;
    case 1:
        *out += printf("%c", lastSymbol);
        break;
    case 2:
        *out += printf("%c%c", lastSymbol, lastSymbol);
        break;
    default:
        *out += printf("%c%i", lastSymbol, repCount);
        break;
    }
}

int main(void)
{
    char symb, lastSymb='.';
    int repCount = 0, symbolCount = 0, outCount = 0;
    while (scanf("%c", &symb) > 0)
    {
      
        if (symb >= 'A' && symb <= 'Z')
        {
            // printf("%c", symb);
            if (symb == lastSymb)
                repCount++;
            else
            {
                swiPrint(repCount, lastSymb, &outCount);
                repCount = 1;
            }
            symbolCount++;
            lastSymb = symb;
        }
        else if(symb!=0x0A)
        {
            swiPrint(repCount, lastSymb, &outCount);
            fprintf(stderr, "Error: Neplatny symbol!\n");
            return 100;
        }
    }
    swiPrint(repCount, lastSymb, &outCount);
    printf("%c", 0x0A);
    fprintf(stderr, "Pocet vstupnich symbolu: %i\nPocet zakodovanych symbolu: %i\nKompresni pomer: %.2f\n", symbolCount, outCount, (float)outCount / symbolCount);
    return 0;
}
