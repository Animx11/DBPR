#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i,j,k,sum = 0;
    int matrixSize = 3;
    int mat1[matrixSize][matrixSize], mat2[matrixSize][matrixSize], mat3[matrixSize][matrixSize];

    srand(time(NULL));

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    for (j = 0; j < matrixSize; j++) {
      for (i = 0; i < matrixSize; i++) {
        for (k = 0; k < matrixSize; k++) {
          sum = sum + mat1[i][k]*mat2[k][j];
        }
 
        mat3[i][j] = sum;
        sum = 0;
      }
    }


    return 0;
}