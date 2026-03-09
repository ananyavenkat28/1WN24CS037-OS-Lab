#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], pr[n], rt[n], wt[n], tt[n];
    for(int i=0; i<n; i++) {
        printf("Enter arrival time, burst time, priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    int complete = 0, t = 0, highest = INT_MAX, current = -1, finish_time;

    while(complete != n) {
        highest = INT_MAX;
        current = -1;
        for(int j=0; j<n; j++) {
            if(at[j] <= t && rt[j] > 0 && pr[j] < highest) {
                highest = pr[j];
                current = j;
            }
        }

        if(current == -1) { t++; continue; }

        rt[current]--;
        if(rt[current] == 0) {
            complete++;
            finish_time = t + 1;
            wt[current] = finish_time - bt[current] - at[current];
            if(wt[current] < 0) wt[current] = 0;
            tt[current] = finish_time - at[current];
        }
        t++;
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTT\n");
    for(int i=0; i<n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], wt[i], tt[i]);

    return 0;
}
