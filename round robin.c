#include <stdio.h>

int main() {
    int n, i, tq, time = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    printf("Enter Burst Time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // Remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int remaining = n;

    // Round Robin Logic
    while (remaining > 0) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remaining--;
                }
            }
        }

        if (done == 1)
            break;
    }

    // Calculate Turnaround Time
    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Display Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
