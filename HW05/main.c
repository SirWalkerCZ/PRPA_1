#include <stdio.h>

int widthNum, heightNum, fenceNum;
int result = 0;

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
        printf("\n");
        spaceCount--;
    }
    
}

//(workNum % 2 == 0) ? evenCount++ : oddCount++;
void drawHouse(int width, int height, int fence)
{
    char filler = ' ';
    int fenceWritten = 0;
    char fenceFiller = '-';
    if (width == height) filler = '*'; // IT SHOULD START AS o BUT FOR SOME REASON THIS WORKS 
    if (height == 0) height = width; //if height was not stated, its the same as the width
    
    for (int i = 0; i < height; i++) //cycles through the house layers
    {
        if (i == 0 || i+1 == height) //writes the top and bottom layer of the house
        {
            for (int j = 0; j < width; j++)
            {
                printf("X");
            }
        }
        else{ //writes middle layers of the house 
            for (int k = 0; k < width; k++)
            {
                (k==0||k+1==width) ?   printf("X") : printf("%c", filler); //writes X at the beggining and end, otherwise writes filler
                if (filler == '*') filler = 'o'; //swaps the fillers
                else if (filler == 'o') filler = '*';
                                
            }
        }

        if (fence != 0 && i >= height-fence) //decides if it should write the fence, based on if it exist and if its at the correct height
        {
            if (fenceWritten==0||fenceWritten==fence-1) //if its top or bottom layer, write "-"
            {
                fenceFiller = '-';
            }
            else {
            fenceFiller = ' ';
            }
            char outOfNames;
            if ((fence % 2)==0)
            {
                outOfNames= fenceFiller;
            }
            else{
                outOfNames = '|';
            }
            
            
            for (int l = 0; l < fence; l++)
            {
                printf("%c", outOfNames);
                if (outOfNames==fenceFiller) outOfNames = '|';
                else if(outOfNames=='|') outOfNames = fenceFiller;
                
            }
            fenceWritten++;    
        }
        printf("\n");
    }
}

int loadval()
{
    int numCount = 0;
    result = scanf("%i", &widthNum); // scans first val
    if (result == 1)
    {
        numCount++;
        result = scanf("%i", &heightNum); // scans second val
        if (result == 1)
        {
            numCount++;
            result = scanf("%i", &fenceNum);
            if (result == 1)
            {
                numCount++;
                return numCount;
            }
            if (result == 0)
            {
                return 0;
            }
            if (result == -1)
            {
                return numCount;
            }
        }
        if (result == 0)
        {
            return 0;
        }
        if (result == -1)
        {
            return numCount;
        }
    }
    if (result == 0)
    {
        return 0;
    }
    if (result == -1)
    {
        return numCount;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    result = loadval();
    switch (result)
    {
    case 1:
        if (testNumInterval(widthNum)==0)
        {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
        drawHouse(widthNum, 0, 0);
        break;
    case 2:
        if (testNumInterval(widthNum)==0||testNumInterval(heightNum)==0)
        {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
        if ((widthNum % 2) == 0)
        {
            fprintf(stderr, "Error: Sirka neni liche cislo!\n");
            return 102;
        }
        drawRoof(widthNum);
        drawHouse(widthNum, heightNum, 0);
        break;
    case 3:
        if (testNumInterval(widthNum)==0||testNumInterval(heightNum)==0||testNumInterval(fenceNum)==0)
        {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
        if ((widthNum % 2) == 0)
        {
            fprintf(stderr, "Error: Sirka neni liche cislo!\n");
            return 102;
        }
        if (fenceNum >= heightNum) // fence cannot be odd and has to be smaller than the house height
        {
            fprintf(stderr, "Error: Neplatna velikost plotu!\n");
            return 103;
        }

        drawRoof(widthNum);
        drawHouse(widthNum, heightNum, fenceNum);

        break;
    default:
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
        break;
    }

    return 0;
}
