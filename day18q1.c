#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int last = arr[n - 1];

        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }

        arr[0] = last;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;

    rotateRight(arr, n, k);
    printArray(arr, n);

    return 0;
}
