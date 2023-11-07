#include <stdio.h>

int a;
int i = 0;
float pocet = 0;
int max = -10001;
int min = 10001;
int licha_cisla = 0;
int sude_cisla = 0;
int pocet_cisel = 0;
int kladne = 0;
int zaporne = 0;
float prumer;
int součet = 0;

int main()
{
    while (scanf("%d", &a) > 0)
    {
        if (a >= -10000 && a <= 10000)
        {
            součet = součet + a;
            pocet++;
            
            if (i < 1)
            {
                printf("\n");
                printf("%d", a);
            }
           
            
            if (i >= 1)
            {
                printf(", %d", a);
                i++;
            }
            i++;
            
            if (a > max)
            {
                max = a;
            }
            if (a < min)
            {
                min = a;
            }
            
            if (a % 2 == 0)
            {
                sude_cisla = sude_cisla + 1;
            }
            else
            {
                licha_cisla = licha_cisla + 1;
            }
            
            if (a < 0)
            {
                zaporne = zaporne + 1;
            }
            if (a > 0)
            {
                kladne = kladne + 1;
            }
        }

        else
        {
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }
    }

    float procs = sude_cisla / pocet * 100;
    float procl = licha_cisla / pocet * 100;
    prumer = součet / pocet;
    float prock = kladne / pocet * 100;
    float procz = zaporne / pocet * 100;

    printf("\n");
    printf("Pocet cisel: %d\n", (int)pocet);
    printf("Pocet kladnych: %d\n", kladne);
    printf("Pocet zapornych: %d\n", zaporne);
    printf("Procento kladnych: %.2f\n", prock);
    printf("Procento zapornych: %.2f\n", procz);
    printf("Pocet sudych: %d\n", sude_cisla);
    printf("Pocet lichych: %d\n", licha_cisla);
    printf("Procento sudych: %.2f\n", procs);
    printf("Procento lichych: %.2f\n", procl);
    printf("Prumer: %.2f\n", prumer);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    
    return 0;
}