#include <stdio.h>

struct MATRIX
{
    int rows;
    int cols;
    int ** matrixP;    
}matrixA, matrixB;

char operator;


void loadMatrix(struct MATRIX matrix){
    int temp;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            if (scanf("%i", &temp)>0)
            {
                matrix.matrixP[j, i] = temp;
                printf("%i ", matrix.matrixP[j, i]);
            }            
        }
        printf("\n");
    }
}



int main(){
    scanf("%i", &matrixA.rows);
    scanf("%i", &matrixB.cols);
    printf("Máme matici vysokou %i a širokou %i\n", matrixA.rows, matrixA.cols);

    int matrix1[matrixA.rows][matrixA.cols];
    matrixA.matrixP = &matrix1;
    loadMatrix(matrixA);

    do
    {
        scanf("%c", &operator);
    } while (operator==10);
    printf("operátor:%c\n", operator);

    scanf("%i", &matrixB.rows);
    scanf("%i", &matrixB.cols);
    printf("Máme matici vysokou %i a širokou %i\n", matrixB.rows, matrixB.cols);

    int matrix2[matrixB.rows][matrixB.cols];
    matrixB.matrixP = &matrix2;
    loadMatrix(matrixB);
    int resultingMatrix
    minus(matrixA, matrixB);

    return 0;
    
}

void plus(struct MATRIX m1, struct MATRIX m2){
    
    if (m1.cols==m2.cols&&m1.rows==m2.rows)
    {

        int resultingMatrix[rows][collums];
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collums; j++)
            {
                resultingMatrix[i][j]=matrix1[i][j]+matrix2[i][j];
                printf("%i ", resultingMatrix[i][j]);
            }
            printf("\n");
        }
         //return resultingMatrix;
    }
    printf("Fuckup, jinak dlouhé :(\n");
    //return 101;
}
void minus(int **matrix1, int **matrix2){
    if (sizeof(matrix1)==sizeof(matrix2))
    {
        size_t rows = sizeof(matrix1) / sizeof(matrix1[0]);
        size_t collums =sizeof(matrix1[0])/sizeof(matrix1[0][0]);
        int resultingMatrix[rows][collums];
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < collums; j++)
            {
                resultingMatrix[i][j]=matrix1[i][j]-matrix2[i][j];
                printf("%i ", resultingMatrix[i][j]);
            }
            printf("\n");
        }
         //return resultingMatrix;
    }
    printf("Fuckup, jinak dlouhé :(\n");
    //return 101;
}