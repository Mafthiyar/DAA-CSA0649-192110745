#include <stdio.h>
#include <stdlib.h>


int** allocateMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}


void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


void addMatrix(int size, int** A, int** B, int** C) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


void subtractMatrix(int size, int** A, int** B, int** C) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


void strassenMultiplication(int size, int** A, int** B, int** C) {

    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);
    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);
    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);
    int** M1 = allocateMatrix(newSize);
    int** M2 = allocateMatrix(newSize);
    int** M3 = allocateMatrix(newSize);
    int** M4 = allocateMatrix(newSize);
    int** M5 = allocateMatrix(newSize);
    int** M6 = allocateMatrix(newSize);
    int** M7 = allocateMatrix(newSize);
    int** AResult = allocateMatrix(newSize);
    int** BResult = allocateMatrix(newSize);

    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }


    addMatrix(newSize, A11, A22, AResult);
    addMatrix(newSize, B11, B22, BResult);
    strassenMultiplication(newSize, AResult, BResult, M1);

    
    addMatrix(newSize, A21, A22, AResult);
    strassenMultiplication(newSize, AResult, B11, M2);

    subtractMatrix(newSize, B12, B22, BResult);
    strassenMultiplication(newSize, A11, BResult, M3);

    subtractMatrix(newSize, B21, B11, BResult);
    strassenMultiplication(newSize, A22, BResult, M4);

    
    addMatrix(newSize, A11, A12, AResult);
    strassenMultiplication(newSize, AResult, B22, M5);

    
    subtractMatrix(newSize, A21, A11, AResult);
    addMatrix(newSize, B11, B12, BResult);
    strassenMultiplication(newSize, AResult, BResult, M6);

    
    subtractMatrix(newSize, A12, A22, AResult);
    addMatrix(newSize, B21, B22, BResult);
    strassenMultiplication(newSize, AResult, BResult, M7);

    
    addMatrix(newSize, M1, M4, AResult);
    subtractMatrix(newSize, AResult, M5, BResult);
    addMatrix(newSize, BResult, M7, C11);

    
    addMatrix(newSize, M3, M5, C12);

    
    addMatrix(newSize, M2, M4, C21);


    subtractMatrix(newSize, M1, M2, AResult);
    addMatrix(newSize, AResult, M3, BResult);
    addMatrix(newSize, BResult, M6, C22);


    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);
    freeMatrix(C11, newSize);
    freeMatrix(C12, newSize);
    freeMatrix(C21, newSize);
    freeMatrix(C22, newSize);
    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);
    freeMatrix(AResult, newSize);
    freeMatrix(BResult, newSize);
}

int main() {
    int size;

    printf("Enter the size of the matrix (must be a power of 2): ");
    scanf("%d", &size);

    int** A = allocateMatrix(size);
    int** B = allocateMatrix(size);
    int** C = allocateMatrix(size);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassenMultiplication(size, A, B, C);

    printf("Result matrix C:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}
