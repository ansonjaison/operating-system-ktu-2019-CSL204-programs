#include<stdio.h>

struct Process {
    int id, at, bt, ct, tat, wt, pr;
} p[100], temp;

void main() {
    int i, j, k, sum = 0, n, avgt, avgw, tott = 0, totw = 0, flag = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the process id : ");
        scanf("%d", &p[i].id);
        printf("Enter the arrival time : ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time : ");
        scanf("%d", &p[i].bt);
        printf("Enter the priority : ");
        scanf("%d", &p[i].pr);
    }

    for (i = 1; i < n; i++) {
        if (p[i].at < p[0].at) {
            temp = p[i];
            p[i] = p[0];
            p[0] = temp;
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n - 1; j++) {
            if (p[j].pr > p[j + 1].pr) {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (p[i].at == 0) {
            flag = 1;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        p[i].ct = p[0].at;
        for (j = 0; j <= i; j++) {
            p[i].ct += p[j].bt;
        }
    }
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    printf("TABLE REPRESENTATION\nPID\tAT\tBT\tCT\tTAT\tWT\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].pr);
    }
    printf("GANTT CHART\n");
    printf("\t");
    if (flag != 1) {
        printf("-----");
    }
    for (i = 0; i < n; i++) {
        printf("-----");
    }
    printf("\n\t");
    if (flag != 1) {
        printf("|    ");
    }
    for (i = 0; i < n; i++) {
        printf("| %d  ", p[i].id);
    }
    printf("|\n\t");
    if (flag != 1) {
        printf("-----");
    }
    for (i = 0; i < n; i++) {
        printf("-----");
    }
    printf("\n\t0");
    if (flag != 1) {
        printf("   %d", p[0].at);
    }
    for (i = 0; i < n; i++) {
        printf("   %d", p[i].ct);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        tott = tott + p[i].tat;
        totw = totw + p[i].wt;
    }
    avgt = tott / n;
    avgw = totw / n;
    printf("Average wait time : %d\nAverage turn around time : %d\n", avgw, avgt);
}
