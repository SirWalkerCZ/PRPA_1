#include <stdio.h>
#include <stdlib.h>

int main() {
    int velikost;
    

    scanf("%d", &velikost);
    

    // Vytvoření paměti pro oba řetězce
    char *retezec1 = (char *)malloc(velikost+1 * sizeof(char));
    char *retezec2 = (char *)malloc(velikost+1 * sizeof(char));

    for (int i = 0; i < velikost+1; i++) {
        printf("%i", scanf(" %c", &retezec1[i]));  // Mezeru před %c používáme pro přeskočení bílých znaků (včetně nových řádků)¨
        if (i == velikost && retezec1[i] != '\0') {
            printf("Chyba: Delka retezce nesouhlasi s ocekavanou velikosti.\n");
            return 101;
        }
        
        if ((retezec1[i] < 'a' || retezec1[i] > 'z') && (retezec1[i] < 'A' || retezec1[i] > 'Z')) {
            printf("Chyba: Znak musi byt v intervalu a-z nebo A-Z.%c\n", retezec1[1]);
            return 1;  // Ukazuje na chybu
        }
    }

    // Nulový znak pro ukončení řetězce
    retezec1[velikost] = '\0';

    for (int i = 0; i < velikost; i++) {
        scanf(" %c", &retezec2[i]);
        if ((retezec2[i] < 'a' || retezec2[i] > 'z') && (retezec2[i] < 'A' || retezec2[i] > 'Z')) {
            printf("Chyba: Znak musi byt v intervalu a-z nebo A-Z.\n");
            return 1;  // Ukazuje na chybu
        }
    }

    // Nulový znak pro ukončení řetězce
    retezec2[velikost] = '\0';

    // Výpis načtených řetězců
    printf("%s", retezec1);
    printf("%s", retezec2);

    // Uvolnění paměti
    free(retezec1);
    free(retezec2);

    return 0;
}
