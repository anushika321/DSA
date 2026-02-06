#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0)
        return 0;

    int k = 1;  // index for next unique element

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;   // number of unique elements
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = removeDuplicates(arr, n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
