#include <stdio.h>

int countSubarraysSumZero(int arr[], int n) {
    int count = 0;
    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            if (sum == 0) count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Number of subarrays with sum 0: %d\n", countSubarraysSumZero(arr, n));
    return 0;
}