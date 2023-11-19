#include <stdio.h>

int cislo, cislo2, cislo3;
int result;

int testNumInterval(int num){    
    if (num < 70 && num > 2)
    {
        return 1;
    }
    else{

        return 0;
    }
    
}
void drawRoof(int baseSize){
    int spaceCount = baseSize/2; //this should round down the odd numbers 
    while (spaceCount != 0)
    {
        for (int i = 0; i < spaceCount; i++) //prints spaces left to the roof
        {
            printf(" ");
        }
        if (spaceCount == baseSize/2) // top of the roof is always one X
        {
            printf("X");
        }
        else{
            printf("X");
            for (int j = 0; j < baseSize-(2*spaceCount)-2; j++) //this should print the middle spaces
            {
                printf(" ");
            }
            printf("X");
        }
        for (int i = 0; i < spaceCount; i++) //prints spaces right to the roof
        {
            printf(" ");
        }

        printf("\n");
        spaceCount--;
    }
    
}

//(workNum % 2 == 0) ? evenCount++ : oddCount++;
void drawHouse(int width, int height)
{
    char filler = ' ';
    if (width == height) filler = '*'; // IT SHOULD START AS o BUT FOR SOME REASON THIS WORKS 
    if (height == 0) height = width;
    
    for (int i = 0; i < height; i++)
    {
        if (i == 0 || i+1 == height)
        {
            for (int j = 0; j < width; j++)
            {
                printf("X");
            }
            printf("\n");
        }
        else{
            for (int k = 0; k < width; k++)
            {
                (k==0||k+1==width) ?   printf("X") : printf("%c", filler);
                if (filler == '*') filler = 'o';
                else if (filler == 'o') filler = '*';
                                
            }
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {

    result = scanf("%i%i%i", &cislo, &cislo2, &cislo3);

    switch (result)
    {
    case -1:
        printf("Weird as fuuuck");
        return 255;
    case 0:
        fprintf(stderr, "Error: Chybny vstup!");
        return 100;
    case 1:
        if (testNumInterval(cislo)==0)
        {
            fprintf(stderr, "Error: Vstup mimo interval!");
            return 101;
        }
        drawHouse(cislo, 0);
        break;
    case 2:
        if (testNumInterval(cislo)==0||testNumInterval(cislo2)==0)
        {
            fprintf(stderr, "Error: Vstup mimo interval!");
            return 101;
        }
        if ((cislo % 2 == 0))
        {
            fprintf(stderr, "Error: Sirka neni liche cislo!");
            return 102;
        }
        drawRoof(cislo);
        drawHouse(cislo, cislo2);
        break;
    case 3:
        printf("\n3 cislo");
        break;
    default:
        printf("\nMoc cisel voe");
        break;
    }

    return 0;
}
