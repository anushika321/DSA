#include <stdio.h>

int isIdentityMatrix(int matrix[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] != 1)
                    return 0;
            }
            else
            {
                if (matrix[i][j] != 0)
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[100][100];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    if (isIdentityMatrix(matrix, n))
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}