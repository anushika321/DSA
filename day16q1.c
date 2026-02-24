#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 1, 4, 2};
    int n = 7;

    int freq[100] = {0};  // assuming elements are < 100

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequency
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 0) {
            printf("%d -> %d\n", i, freq[i]);
        }
    }

    return 0;
}
