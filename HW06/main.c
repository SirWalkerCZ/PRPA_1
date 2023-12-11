#include <stdio.h>

int srovnej(char *arr1, char *arr2, int lenght)
{
    int pocet = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (arr1[i] == arr2[i])
        {
            pocet++;
        }
    }
    return pocet;
}

void posun(char *in, char *out, int pocet)
{
    char newCharacter;

    for (int i = 0; i < pocet; i++)
    {
        newCharacter = in[i] + 1;
        if (newCharacter > 'Z' && newCharacter < 'a')
        {
            newCharacter = 'a';
        }
        else if (newCharacter > 'z')
        {
            newCharacter = 'A';
        }

        out[i] = newCharacter;
    }
}



int main()
{
    int sizeArr = 0;


    if (scanf("%i", &sizeArr) <= 0)
    {
        fprintf(stderr, "Error: Chybny vstup!");
        return 100;
    }
    char inArrChar[sizeArr];
    char decodeArrChars[sizeArr];
    char tempArray[sizeArr];
    char outArray[sizeArr];


    char uselessChar;
    int MAX = 0;
    char input = 0;
    int poceter = 0;


    scanf("%c", &uselessChar);
    //load the first array
    while (scanf("%c", &input) > 0)
    {
        if (input == '\n')
        {
            break;
        }

        if (poceter > sizeArr)
        {
            fprintf(stderr, "Error: Chybna delka vstupu!");
            return 101;
        }

        if (input < 'A' || (input > 'Z' && input < 'a') || input > 'z')
        {
            fprintf(stderr, "Error: Chybny vstup!");
            return 100;
        }

        inArrChar[poceter] = input;
        poceter++;
    }

    if (poceter < sizeArr)
    {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        return 101;
    }

    //load the second array
    input = 0; 
    poceter = 0;

    while (scanf("%c", &input) > 0)
    {
        if (input == '\n')
        {
            break;
        }

        if (poceter > sizeArr)
        {
            fprintf(stderr, "Error: Chybna delka vstupu!");
            return 101;
        }

        if (input < 'A' || (input > 'Z' && input < 'a') || input > 'z')
        {
            fprintf(stderr, "Error: Chybny vstup!");
            return 100;
        }

        decodeArrChars[poceter] = input;
        poceter++;
    }

    if (poceter < sizeArr)
    {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        return 101;
    }

    posun(inArrChar, tempArray, sizeArr);

    while (srovnej(inArrChar, tempArray, sizeArr) != sizeArr)
    {
        int COMMON;

        posun(tempArray, tempArray, sizeArr);

        COMMON = srovnej(decodeArrChars, tempArray, sizeArr);
        if (COMMON > MAX)
        {
            MAX = COMMON;
            for (int i = 0; i < sizeArr; i++)
            {
                outArray[i] = tempArray[i];
            }
        }
    }
    for (int i = 0; i < sizeArr; i++)
    {
        printf("%c", outArray[i]);
    }
    printf("\n");
    return 0;
}
