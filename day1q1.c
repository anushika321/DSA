#include <stdio.h>

int main() {
    int a[10] = {10, 20, 30, 40};
    int n = 4, pos = 3, x = 25;

    for (int i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = x;
    n++;

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
