#include <stdio.h>

int main() {
    int i, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess\t|Turnaround Time|Waiting Time\n");
    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= time_quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= time_quantum;
            time += time_quantum;
        }
        if (rt[i] == 0 && flag == 1) {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
            wait_time += time - at[i] - bt[i];
            turnaround_time += time - at[i];
            flag = 0;
        }
        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)turnaround_time / n);

    return 0;
}