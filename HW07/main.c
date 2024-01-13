#include <stdio.h>
#include <stdlib.h>

struct MATRIX
{
    int rows;
    int cols;
    int ** matrixP;    
}matrixA, matrixB;

char operator;


int loadMatrix(struct MATRIX matrix){
    int temp;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            if (scanf("%i", &temp)>0)
            {
                matrix.matrixP[i][j] = temp;
                //printf("%i ", matrix.matrixP[i][j]);
            }
            else{
                return 100;
            }  
        }
        //printf("\n");
    }
    return 0;
}

void minus(struct MATRIX m1,struct MATRIX m2){ 
    for (size_t i = 0; i < m1.rows; i++)
    {
        for (size_t j = 0; j < m2.cols; j++)
        {                                         
            printf("%i", m1.matrixP[i][j]-m2.matrixP[i][j]);
            if (j != m2.cols - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void plus(struct MATRIX m1,struct MATRIX m2){
    for (size_t i = 0; i < m1.rows; i++)
    {
        for (size_t j = 0; j < m2.cols; j++)
        {                                         
            printf("%i", m1.matrixP[i][j]+m2.matrixP[i][j]);
            if (j != m2.cols - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }  

}

void multiply(struct MATRIX m1,struct MATRIX m2){
    
    for (int i = 0; i < m1.rows; ++i) {
        for (int j = 0; j < m2.cols; ++j) {
            int tempResult = 0;
            for (int k = 0; k < m1.cols; ++k) {
                tempResult += m1.matrixP[i][k] * m2.matrixP[k][j];
            }
            printf("%i", tempResult);
            if (j != m2.cols - 1){
                printf(" ");
            }
        }
        printf("\n");
    }

}

void freeMemory(){
    // Free memory
    for (int i = 0; i < matrixA.rows; ++i) {
        free(matrixA.matrixP[i]);
    }
    free(matrixA.matrixP);

    for (int i = 0; i < matrixB.rows; ++i) {
        free(matrixB.matrixP[i]);
    }
    free(matrixB.matrixP);
}


int main(){
    scanf("%i", &matrixA.rows);
    scanf("%i", &matrixA.cols);
    //printf("Máme matici vysokou %i a širokou %i\n", matrixA.rows, matrixA.cols);

    matrixA.matrixP = malloc(matrixA.rows * sizeof(int *));
    for (int i = 0; i < matrixA.rows; ++i) {
        matrixA.matrixP[i] = (int *)malloc(matrixA.cols * sizeof(int));
    }
    if(loadMatrix(matrixA)==100){
        fprintf(stderr, "Error: Chybny vstup!\n");
        freeMemory();
        return 100;
    }

    scanf(" %c", &operator);
    //printf("%c\n", operator);


    scanf("%i", &matrixB.rows);
    scanf("%i", &matrixB.cols);
    //printf("Máme matici vysokou %i a širokou %i\n", matrixB.rows, matrixB.cols);

    matrixB.matrixP = malloc(matrixB.rows * sizeof(int *));
    for (int i = 0; i < matrixB.rows; ++i) {
        matrixB.matrixP[i] = (int *)malloc(matrixB.cols * sizeof(int));
    }
    if(loadMatrix(matrixB)==100){
        fprintf(stderr, "Error: Chybny vstup!\n");
        freeMemory();
        return 100;
    }


    //printf("Result:\n");

    switch (operator)
    {
    case '*':
        if(matrixA.cols != matrixB.rows){
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory();
            return 100;
        }
        printf("%i %i\n", matrixA.rows, matrixB.cols);
        multiply(matrixA, matrixB);
        break;
    case '+':
        if (matrixA.cols!=matrixB.cols&&matrixA.rows!=matrixB.rows){
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory();
            return 100;
        }
        printf("%i %i\n", matrixA.rows, matrixB.cols);
        plus(matrixA, matrixB);
        break;
    case '-':
        if (matrixA.cols!=matrixB.cols&&matrixA.rows!=matrixB.rows){
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory();
            return 100;
        }
        printf("%i %i\n", matrixA.rows, matrixB.cols);
        minus(matrixA, matrixB);
        break;
    default:
        break;
    }

    freeMemory();

    return 0;
    
}
