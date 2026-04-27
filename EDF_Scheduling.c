#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival;       // arrival time
    int Ci;            // execution time
    int Di;            // deadline
    int remaining;     // remaining execution time
    int completed;     // flag
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *plist = malloc(n * sizeof(Process));
    double U = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, execution time (Ci), deadline (Di) for Process %d: ", i+1);
        scanf("%d %d %d", &plist[i].arrival, &plist[i].Ci, &plist[i].Di);
        plist[i].id = i+1;
        plist[i].remaining = plist[i].Ci;
        plist[i].completed = 0;
        U += (double)plist[i].Ci / plist[i].Di;
    }

    // Step 2: Feasibility check
    printf("\nCPU Utilization U = %.4f\n", U);
    if (U > 1.0) {
        printf("Scheduling not feasible (deadlines may be missed)\n");
    } else {
        printf("Scheduling feasible\n");
    }

    // Step 3: Scheduling loop
    int t = 0;
    int finished = 0;
    printf("\nScheduling simulation:\n");

    while (finished < n) {
        // Build Ready List
        int selected = -1;
        int min_deadline = 1e9;

        for (int i = 0; i < n; i++) {
            if (!plist[i].completed && plist[i].arrival <= t && plist[i].remaining > 0) {
                if (plist[i].Di < min_deadline) {
                    min_deadline = plist[i].Di;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("Time %d: CPU Idle\n", t);
            t++;
            continue;
        }

        // Execute selected process for 1 unit
        printf("Time %d: Executing Process %d\n", t, plist[selected].id);
        plist[selected].remaining--;

        if (plist[selected].remaining == 0) {
            plist[selected].completed = 1;
            finished++;
            printf("Process %d completed at time %d\n", plist[selected].id, t+1);
        }

        t++;
    }

    free(plist);
    return 0;
}
