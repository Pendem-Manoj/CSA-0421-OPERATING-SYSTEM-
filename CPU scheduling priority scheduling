#include <stdio.h>
int main()
{
    int n, i, j, t;
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n];

    printf("Enter Burst Time and Priority (Lower number = Higher priority):\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &bt[i], &pr[i]);

    // Sort based on priority
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(pr[i] > pr[j])
            {
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pr[i]; pr[i] = pr[j]; pr[j] = t;
            }

    // Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Turnaround Time
    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nBT  PR  WT  TAT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d   %d   %d   %d\n", bt[i], pr[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
