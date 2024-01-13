#include <stdio.h>
#include <stdlib.h>

int compareNumbers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* numbers = NULL;
int arraySize = 0;
int capacity = 0;
int num;
int histogram;


int main(){
    if (scanf("%i", &histogram)<1)
    {
        fprintf(stderr, "Error: Chyba histogramu!\n");
        return 100;
    }
    
    while (scanf("%i", &num) == 1) {
        if (arraySize == capacity) {
            capacity += 10;
            int* temp = realloc(numbers, capacity * sizeof(int));

            if (temp == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                free(numbers);
                return 1;
            }

            numbers = temp;
        }
        numbers[arraySize] = num;
        arraySize++;
    }

    //  printf("Numbers entered:\n");

    //  for (int i = 0; i < arraySize; i++) {
    //      printf("%d ", numbers[i]);
    // }
    // printf("\n");
    qsort(numbers, arraySize, sizeof(numbers[0]), compareNumbers);
    float median;
    (arraySize % 2 == 0) ? (median = (float)numbers[arraySize/2]) : (median = ((float)(numbers[arraySize/2] + numbers[(arraySize/2)+1])) / 2.0);
    printf("Median %.2f\nPocet cisel: %i\nMin. hodnota: %i\nMax. hodnota: %i\n", median, arraySize, numbers[0], numbers[arraySize-1]);
    float size = (float)(numbers[arraySize-1]-numbers[0])/histogram;
    printf("Histogram:\n");
    float edgeCases[histogram+1];

    //vytvoření limitů histogramu
    for (size_t i = 0; i < histogram; i++)
    {
        edgeCases[i] = (float)numbers[0]+(float)i*size;
    }
    edgeCases[histogram] = numbers[arraySize-1];

    //vytvoření hodnot histogramu
    int *histogramValues= calloc(histogram, sizeof(int));
    for (size_t i = 0; i < arraySize; i++)
    {
        int bin_result = (numbers[i]-numbers[0])/size;
        if (bin_result ==histogram)
        {
           bin_result--;
        }
        //printf("binresult: %i\n", bin_result);
        histogramValues[bin_result]++;
    }

    //tvorba koeficientu na lineární škálování
    int maxHisVal = -__INT_MAX__;
    int loc = 0; //lokace maximální hodnoty histogramu
    for (size_t i = 0; i < histogram; i++)
    {
        if (maxHisVal<histogramValues[i])
        {
            maxHisVal = histogramValues[i];
            loc = i;
        }        
    }
    double coeficient = (double)25/histogramValues[loc];
    //printf("%f, max %i, test: %f\n", coeficient, maxHisVal, (double)maxHisVal*coeficient);

    //vypsání histogramu
    char *line =malloc(25*sizeof(char));
    for (size_t i = 0; i < histogram; i++)
    {    
        int temp = (double)histogramValues[i]*coeficient;
        //printf("%i\t", temp);
        for (int j = 0; j < temp; j++)
        {
            line[j]='=';
        }      
        line[temp]='\0';   
        printf("%5.1f - %5.1f |%s\n", edgeCases[i], edgeCases[i+1], line);
    }

    free(numbers);
    free(line);
    free(histogramValues);

    return 0;

}
