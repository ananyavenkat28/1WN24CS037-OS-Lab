#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int rt;         // Remaining Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

void roundRobin(struct Process proc[], int n, int quantum) {
    int t = 0; // Current time
    int done;

    // Reset values
    for (int i = 0; i < n; i++) {
        proc[i].rt = proc[i].bt;
        proc[i].wt = 0;
        proc[i].tat = 0;
    }

    printf("\n--- Round Robin (Quantum = %d) ---\n", quantum);

    // Loop until all processes are finished
    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].rt > 0) {
                done = 0;
                if (proc[i].rt > quantum) {
                    t += quantum;
                    proc[i].rt -= quantum;
                } else {
                    t += proc[i].rt;
                    proc[i].wt = t - proc[i].bt;
                    proc[i].rt = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    // Calculate Turnaround Time
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }

    // Display results
    printf("PID\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
        avgWT += proc[i].wt;
        avgTAT += proc[i].tat;
    }
    printf("Average Waiting Time = %.2f\n", avgWT/n);
    printf("Average Turnaround Time = %.2f\n", avgTAT/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i+1;
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &proc[i].bt);
    }

    // Run with two different quantum values
    roundRobin(proc, n, 2);  // Example quantum = 2
    roundRobin(proc, n, 4);  // Example quantum = 4

    return 0;
}

