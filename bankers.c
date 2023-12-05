#include <stdio.h>

int main() {
    int n, m, i, j, k;
    n = 5;  // Number of processes
    m = 3;  // Number of resources

    int available[m];
    int max[n][m];
    int allocation[n][m];
    int need[n][m];

    // Initialize the available resources
    for (i = 0; i < m; i++) {
        printf("Enter the number of available instances of resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    // Enter the maximum resources required by each process
    for (i = 0; i < n; i++) {
        printf("Enter the maximum resources required by process %d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Enter the resources currently allocated to each process
    for (i = 0; i < n; i++) {
        printf("Enter the resources currently allocated to process %d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Check for a safe sequence
    int work[m];
    for (i = 0; i < m; i++) {
        work[i] = available[i];
    }

    int finish[n];
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int safe_sequence[n];
    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == m) {
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is in unsafe state\n");
            return 0;
        }
    }

    printf("System is in safe state\nSafe sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}