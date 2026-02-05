#include <stdio.h>

int main() {
    int arr[50] = {10, 20, 30, 40, 50};
    int n = 5, key = 30, pos = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            pos = i;
            break;
        }
    }

    if(pos != -1) {
        for(int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
