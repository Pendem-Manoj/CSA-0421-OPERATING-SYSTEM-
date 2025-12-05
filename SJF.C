#include <stdio.h>

int main()
{
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter burst time of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort burst times in ascending order
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }

    // Waiting time calculation
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Turnaround time calculation
    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    // Display results
    printf("\nBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);

    // Average calculation
    float avg_wt = 0, avg_tat = 0;
    for(i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
