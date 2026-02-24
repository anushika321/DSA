#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    sort(arr, n);

    printf("Minimum: %d\n", arr[0]);
    printf("Maximum: %d\n", arr[n-1]);

    return 0;
}
