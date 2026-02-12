#include <stdio.h>

int main() {
    int n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input
    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetric
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                printf("Matrix is NOT Symmetric\n");
                return 0;
            }
        }
    }

    printf("Matrix is Symmetric\n");
    return 0;
}
