#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival times and burst times of the processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculate the waiting time, turnaround time, and other metrics
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + at[i - 1];
        tat[i] = bt[i - 1] + wt[i - 1];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}