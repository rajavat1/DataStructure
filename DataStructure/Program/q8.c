#include <stdio.h>

int main() {
    int mat1[3][3], mat2[3][3], result[3][3];
    printf("Enter elements for Matrix 1 (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for Matrix 2 (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\nMatrix 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\nMultiplication Result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
