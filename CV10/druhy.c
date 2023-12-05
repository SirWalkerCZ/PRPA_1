#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char r1[] = "Den otevřených dveřích";

    //frajersky skipnu první 4 písmena
    printf("%s\n", r1+4);
    //příkazy s N navíc tak jsou bezpečné znaky
    return 0;
}
