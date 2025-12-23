#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[10][10];
    int sparse[100][3];
    int rows, cols;
    int i, j;
    int count = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n matris \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }
        }
    }
    for (i = 0; i < count; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
