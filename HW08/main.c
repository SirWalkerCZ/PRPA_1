#include <stdio.h>
#include <stdlib.h>

int main(){
    int* numbers = NULL;
    int size = 0;
    int capacity = 0;
    int num;
    int min = __INT32_MAX__;
    int max = -__INT32_MAX__;

    while (scanf("%d", &num) == 1) {
        if (size == capacity) {
            capacity += 10;
            int* temp = realloc(numbers, capacity * sizeof(int));

            if (temp == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                free(numbers);
                return 1;
            }

            numbers = temp;
        }
        if(num>max)max=num;
        if(num<min)min=num;
        numbers[size] = num;
        size++;
    }

     printf("Numbers entered:\n");

     for (int i = 0; i < size; i++) {
         printf("%d\t", numbers[i]);
     }

    //bubble sort
    for (int i = 0; i < size-1; i++)
    {
        if (numbers[i+1]<numbers[i])
        {
            int temp = numbers[i+1];
            numbers[i+1] = numbers[i];
            numbers[i] = temp;
        }
    }
    

    printf("Median\n");

    printf("Numbers entered:\n");

     for (int i = 0; i < size; i++) {
        printf("%d\t", numbers[i]);
     }

    free(numbers);

    return 0;

}