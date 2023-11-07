#include <stdio.h>

/*
Ze standarního vstupu načítejte celá čísla pomocí funkce scanf() v rozsahu [0; 100] včetně krajních hodnot,
dokud na něm jsou data, nebo dokud čtení neskončí chybou.
Cílem programu je detekovat ve vstupních datech posloupnosti stejných čísel a určit délku této posloupnosti
V případě že načtené číslo leží mimo zadaný interval vypište na standardní výstup délku právě nalezené posloupnosti
(pokud taková existuje), na nový řádek vypište “Error: Vstup je mimo interval!” a program ukončete s návratovou hodnotou 100.
Nevypisujte již žádná další čísla.
Výpis chyby je na samostatném řádku, tj. pokud nebyla dosud nalezena žádná posloupnost opakujících se čísel,
vytiskne se jediný řádek s chybou.
Každý řádek vypsaný na standardní výstup je ukončen znakem \n.
*/
int main(){
    int num, lastnum, i = 1;
    while(scanf("%i", &num)>0){
        if (num==lastnum)
        {
            i++;
        }
        else if (i > 1)
        {
            printf("%ix %i\n", i, lastnum);
            i=1;
        }  
                if (num>100 || num<0)
        {
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }
        lastnum = num;     
    }
    if (i >1)
    {
        printf("%ix %i\n", i, lastnum);
    }  

    return 0;
}
