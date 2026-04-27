#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id;
    double Ci;   // execution time
    double Ti;   // period
    int priority; // smaller Ti → higher priority
    double next_release;
    double remaining_time;
} Task;

int comparePeriod(const void *a, const void *b) {
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    if (t1->Ti < t2->Ti) return -1;
    if (t1->Ti > t2->Ti) return 1;
    return 0;
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task *tasks = malloc(n * sizeof(Task));
    double U = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Enter execution time (Ci) and period (Ti) for Task %d: ", i+1);
        scanf("%lf %lf", &tasks[i].Ci, &tasks[i].Ti);
        tasks[i].id = i+1;
        tasks[i].next_release = 0;
        tasks[i].remaining_time = 0;
        U += tasks[i].Ci / tasks[i].Ti;
    }

    // Step 2: RMS Bound
    double bound = n * (pow(2.0, 1.0/n) - 1.0);
    printf("\nCPU Utilization U = %.4f\n", U);
    printf("RMS Bound = %.4f\n", bound);

    if (U <= bound) {
        printf("Schedulable using RMS\n");
    } else {
        printf("Not guaranteed schedulable (need further analysis)\n");
    }

    // Step 4: Assign Priorities
    qsort(tasks, n, sizeof(Task), comparePeriod);
    for (int i = 0; i < n; i++) {
        tasks[i].priority = i+1; // smaller period → higher priority
        printf("Task %d assigned priority %d\n", tasks[i].id, tasks[i].priority);
    }

    // Step 5: Scheduling Loop (basic simulation for a fixed time window)
    int simulation_time = 20; // simulate 20 time units
    printf("\nScheduling simulation for %d time units:\n", simulation_time);

    for (int t = 0; t < simulation_time; t++) {
        // release tasks at their period
        for (int i = 0; i < n; i++) {
            if (t == tasks[i].next_release) {
                tasks[i].remaining_time = tasks[i].Ci;
                tasks[i].next_release += tasks[i].Ti;
            }
        }

        // select highest priority READY task
        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                selected = i;
                break; // tasks are sorted by priority already
            }
        }

        if (selected != -1) {
            printf("Time %d: Executing Task %d\n", t, tasks[selected].id);
            tasks[selected].remaining_time--;
        } else {
            printf("Time %d: CPU Idle\n", t);
        }
    }

    free(tasks);
    return 0;
}
