#include <stdio.h>

void boundaryToCenter(int matrix[][100], int rows, int cols)
{
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // 1. Left → Right
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // 2. Top → Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // 3. Right → Left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // 4. Bottom → Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}