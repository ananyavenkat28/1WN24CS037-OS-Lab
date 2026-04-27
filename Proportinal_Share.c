#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival;       // arrival time
    int Ci;            // execution time
    int remaining;     // remaining execution time
    int weight;        // weight of process
    int completed;     // flag
} Process;

int main() {
    int n, TIME_QUANTUM;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter TIME_QUANTUM: ");
    scanf("%d", &TIME_QUANTUM);

    Process *plist = malloc(n * sizeof(Process));
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, execution time (Ci), weight for Process %d: ", i+1);
        scanf("%d %d %d", &plist[i].arrival, &plist[i].Ci, &plist[i].weight);
        plist[i].id = i+1;
        plist[i].remaining = plist[i].Ci;
        plist[i].completed = 0;
        total_weight += plist[i].weight;
    }

    int finished = 0;
    int t = 0;
    printf("\nScheduling simulation:\n");

    while (finished < n) {
        int any_ready = 0;

        for (int i = 0; i < n; i++) {
            if (!plist[i].completed && plist[i].arrival <= t) {
                any_ready = 1;
                // calculate proportional time slice
                int time_slice = (int)((double)plist[i].weight / total_weight * TIME_QUANTUM);
                if (time_slice <= 0) time_slice = 1; // ensure at least 1 unit

                printf("Time %d: Executing Process %d for %d units\n", t, plist[i].id, time_slice);

                plist[i].remaining -= time_slice;
                t += time_slice;

                if (plist[i].remaining <= 0) {
                    plist[i].completed = 1;
                    finished++;
                    total_weight -= plist[i].weight;
                    printf("Process %d completed at time %d\n", plist[i].id, t);
                }
            }
        }

        if (!any_ready) {
            printf("Time %d: CPU Idle\n", t);
            t++;
        }
    }

    free(plist);
    return 0;
}
