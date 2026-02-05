#include <stdio.h>

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int n = 5, key = 45;
    int count = 0, found = 0;

    for(int i = 0; i < n; i++) {
        count++;                // comparison made
        if(arr[i] == key) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Element found\n");
    else
        printf("Element not found\n");

    printf("Number of comparisons = %d", count);

    return 0;
}
