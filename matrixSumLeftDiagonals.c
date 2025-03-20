#include <stdio.h>

int main() {
    int rows, cols;

    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    int sum = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix :\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rows && i < cols; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);
    return 0;
}
