#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int start = 0, end = n - 1, temp;

    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
