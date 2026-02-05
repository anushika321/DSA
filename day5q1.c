#include <stdio.h>

int main() {
    int time[] = {1030, 945, 1100, 1000}; // arrival times
    int n = 4, temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(time[j] > time[j + 1]) {
                temp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = temp;
            }
        }
    }

    printf("Arranged Arrival Logs:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", time[i]);
    }

    return 0;
}
