#include <stdio.h>

void sortByPriority(int proc_id[], int at[], int bt[], int pr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = proc_id[i];
                proc_id[i] = proc_id[j];
                proc_id[j] = temp;
            }
        }
    }
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int proc_id[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    double avg_tat = 0.0, ttat = 0.0, avg_wt = 0.0, twt = 0.0;

    for (int i = 0; i < n; i++)
        proc_id[i] = i + 1;

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter priorities:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    sortByPriority(proc_id, at, bt, pr, n);

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[i])
            current_time = at[i];
        current_time += bt[i];
        ct[i] = current_time;
    }

    for (int i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];

    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    printf("Priority Scheduling:\n");
    printf("PID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", proc_id[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    for (int i = 0; i < n; i++) {
        ttat += tat[i];
        twt += wt[i];
    }

    avg_tat = ttat / (double)n;
    avg_wt = twt / (double)n;

    printf("\nAverage turnaround time: %lf ms\n", avg_tat);
    printf("Average waiting time: %lf ms\n", avg_wt);
}
