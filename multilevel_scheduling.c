#include <stdio.h>

typedef struct {
    int pid;        // Process ID
    int at;         // Arrival Time
    int bt;         // Burst Time
    int type;       // Process Type (0 = System, 1 = User)
    int start;      // Start Time
    int ct;         // Completion Time
    int tat;        // Turnaround Time
    int wt;         // Waiting Time
} Process;

// Function to sort processes by Arrival Time (FCFS order)
void sortByArrival(Process arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].at > arr[j + 1].at) {
                Process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time, Type (0=System,1=User) for process %d: ", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].at, &processes[i].bt, &processes[i].type);
    }

    // Separate into SystemQueue and UserQueue
    Process systemQueue[n], userQueue[n];
    int sysCount = 0, userCount = 0;

    for (int i = 0; i < n; i++) {
        if (processes[i].type == 0)
            systemQueue[sysCount++] = processes[i];
        else
            userQueue[userCount++] = processes[i];
    }

    // Sort both queues by Arrival Time
    sortByArrival(systemQueue, sysCount);
    sortByArrival(userQueue, userCount);

    int time = 0;

    // Execute System Processes
    for (int i = 0; i < sysCount; i++) {
        if (time < systemQueue[i].at)
            time = systemQueue[i].at;
        systemQueue[i].start = time;
        time += systemQueue[i].bt;
        systemQueue[i].ct = time;
        systemQueue[i].tat = systemQueue[i].ct - systemQueue[i].at;
        systemQueue[i].wt = systemQueue[i].tat - systemQueue[i].bt;
    }

    // Execute User Processes
    for (int i = 0; i < userCount; i++) {
        if (time < userQueue[i].at)
            time = userQueue[i].at;
        userQueue[i].start = time;
        time += userQueue[i].bt;
        userQueue[i].ct = time;
        userQueue[i].tat = userQueue[i].ct - userQueue[i].at;
        userQueue[i].wt = userQueue[i].tat - userQueue[i].bt;
    }

    // Display results
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for (int i = 0; i < sysCount; i++) {
        printf("%d\t%d\t%d\tSys\t%d\t%d\t%d\n",
               systemQueue[i].pid, systemQueue[i].at, systemQueue[i].bt,
               systemQueue[i].ct, systemQueue[i].tat, systemQueue[i].wt);
    }
    for (int i = 0; i < userCount; i++) {
        printf("%d\t%d\t%d\tUser\t%d\t%d\t%d\n",
               userQueue[i].pid, userQueue[i].at, userQueue[i].bt,
               userQueue[i].ct, userQueue[i].tat, userQueue[i].wt);
    }

    return 0;
}
