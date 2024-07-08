#include <stdio.h>
#include <string.h>

struct process {
    int at, bt, ct, tat, wt, rem_t;
    char pid[20];
} p[20];

struct done {
    char pid[20];
    int ct;
} d[20];

int main() {
    int n, tq, i, count = 0, j = 0;
    int cmplted = 0, current_t = 0, ttat = 0, twt = 0;
    float avg_tat, avg_wt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    printf("ENTER THE PROCESS DETAILS\n");
    for (i = 0; i < n; i++) {
        printf("PROCESS %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%s", p[i].pid);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
        p[i].rem_t = p[i].bt;
    }

    while (cmplted < n) {
        for (i = 0; i < n; i++) {
            if (p[i].rem_t > 0 && p[i].at <= current_t) {
                if (p[i].rem_t > tq) {
                    p[i].rem_t -= tq;
                    current_t += tq;
                    strcpy(d[j].pid, p[i].pid);
                    d[j].ct = current_t;
                    j++;
                } else {
                    current_t += p[i].rem_t;
                    p[i].ct = current_t;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    cmplted++;
                    ttat += p[i].tat;
                    twt += p[i].wt;
                    p[i].rem_t = 0;
                    strcpy(d[j].pid, p[i].pid);
                    d[j].ct = current_t;
                    j++;
                }
            }
        }
    }

    printf("Process ID\tArrival time\tBurst time\tCompletion time\tTurnaround time\tWaiting time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("--------------------GANTT CHART------------------\n");
    for (i = 0; i < j; i++) {
        printf("|%s\t", d[i].pid);
    }
    printf("|\n0\t");
    for (i = 0; i < j; i++) {
        printf("%d\t", d[i].ct);
    }
    avg_wt = (float)twt / n;
    avg_tat = (float)ttat / n;
    printf("\nAverage Turnaround time: %.2f", avg_tat);
    printf("\nAverage Waiting time: %.2f", avg_wt);

    return 0;
}

/* OUTPUT

Enter the number of processes: 3
Enter the time quantum: 2
ENTER THE PROCESS DETAILS
PROCESS 1:
Process ID: 1
Arrival time: 0
Burst time: 5
PROCESS 2:
Process ID: 2
Arrival time: 1
Burst time: 4
PROCESS 3:
Process ID: 3
Arrival time: 2
Burst time: 6
Process ID      Arrival time    Burst time      Completion time Turnaround time Waiting time
1               0               5               13              13              8
2               1               4               10              9               5
3               2               6               15              13              7
--------------------GANTT CHART------------------
|1      |2      |3      |1      |2      |3      |1      |3      |
0       2       4       6       8       10      12      13      15
Average Turnaround time: 11.67
Average Waiting time: 6.67

*/
