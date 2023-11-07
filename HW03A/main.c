
/*
Ze standarního vstupu načítejte celá čísla pomocí funkce scanf() v rozsahu [-10 000; 10 000] včetně krajních hodnot, dokud na něm
jsou data, nebo dokud čtení neskončí chybou.
Vypište všechna načtená čísla za sebe, oddělená čárkou (za posledním číslem není čárka ani mezera).
V případě že načtené číslo leží mimo zadaný interval vypište na standardní výstup na nový řádek: “Error: Vstup je mimo interval!”
a program ukončete s návratovou hodnotou 100. Nevypisujte již žádná další čísla. Před výpis chyby vložte vždy symbol nového řádku.
Vypište statistiku čísel:
Počet načtených čísel;
Počet kladných čísel;
Počet záporných čísel;
Procentuální podíl kladných a záporných čísel z načtených vstupních hodnot, vypsané (zaokrouhlené funkcí printf())
s přesností na dvě desetinná místa;
Četnosti výskytu sudých a lichých čísel;
Procentuální podíl sudých a lichých čísel z načtených vstupních hodnot, vypsané s přesností na dvě desetinná místa;
Průměr načtených čísel;
Maximální a minimální hodnotu.
*/
#include <stdio.h>
int workNum, lastNum = 10001, scanSuc, numCount = 0, posCount = 0, negCount = 0, numSum = 0, maxCount = -10001, minCount = 10001, oddCount = 0, evenCount = 0;

int main(void)
{
    while (scanf("%i", &workNum) > 0)
    {

        if (workNum <= 10000 && workNum >= -10000)
        {
            numCount++;
            if (lastNum != 10001) // haha to si hezky zprasil
            {
                printf("%i, ", lastNum);
            }

            numSum += workNum;
            lastNum = workNum;
            if (workNum < 0)
            {
                negCount++;
            }
            if (workNum > 0)
            {
                posCount++;
            }
            if (maxCount < workNum)
            {
                maxCount = workNum;
            }
            if (minCount > workNum)
            {
                minCount = workNum;
            }
            (workNum % 2 == 0) ? evenCount++ : oddCount++;
        }
        else
        {
            printf("%i\n", lastNum);
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }
    }
    printf("%i\n", lastNum);
    printf("Pocet cisel: %i\nPocet kladnych: %i\nPocet zapornych: %i\n", numCount, posCount, negCount);
    printf("Procento kladnych: %.2f\nProcento zapornych: %.2f\n", (float)(posCount * 100) / numCount, (float)(negCount * 100) / numCount);
    printf("Pocet sudych: %i\nPocet lichych: %i\n", evenCount, oddCount);
    printf("Procento sudych: %.2f\nProcento lichych: %.2f\n", (float)(evenCount * 100) / numCount, (float)(oddCount * 100) / numCount);
    printf("Prumer: %.2f\nMaximum: %i\nMinimum: %i\n", (float)numSum / numCount, maxCount, minCount);
    return 0;
}
