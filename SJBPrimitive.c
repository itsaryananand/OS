
#include <stdio.h>

int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {6, 2, 8, 3, 4};

    // Sort the processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Print the sorted order
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i]);
    }

    return 0;
}