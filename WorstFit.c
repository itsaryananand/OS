#include <stdio.h>

#define MAX_BLOCKS 50

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
  
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
  
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        } else {
            allocation[i] = -1;
        }
    }
  
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_BLOCKS];
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, m, processSize, n);

   return (0);
}