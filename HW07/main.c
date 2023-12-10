#include <stdio.h>
int height, width;

void loadMatrix(int * matrix){
    int temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (scanf("%i", &temp)>0)
            {
                matrix[j, i] = temp;
            }
            
            
        }
        
    }
}


int main(){
    scanf("%i", &width);
    scanf("%i", &height);
    printf("Máme matici širokou %i a vysokou %i\n", width, height);

    int matrixA[width][height];
    int matrixB[width][height];

    loadMatrix(matrixA);
    
}