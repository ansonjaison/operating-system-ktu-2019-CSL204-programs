#include<stdio.h>
#include<stdlib.h>

int n, m, max[20][20], alloc[20][20], need[20][20], avail[40], finish[20], count = 0, flag = 0;

void safety() {
    int i = 0, j = 0, k;
    while (1) {
        flag = 0;
        if (finish[i] == 0) {
            for (j = 0; j < m; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                for (k = 0; k < m; k++) {
                    avail[k] = avail[k] + alloc[i][k];
                }
                finish[i] = 1;
            }

            if (finish[i] == 1) {
                count++;
                printf("P%d\t", i);
                if (count == n)
                    break;
            }
        }
        if (i == n - 1)
            i = 0;
        else
            i++;
    }
}

void main() {
    int i, j;
    printf("\nEnter no. of processes:\t ");
    scanf("%d", &n);
    printf("\nEnter no. of resource instances:\t ");
    scanf("%d", &m);

    printf("\n\nEnter MAXIMUM resources requirement of processes");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\t\n", i);
        for (j = 0; j < m; j++) {
            printf("\t'%d':", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\n\nEnter ALLOCATED resources requirement of processes");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\t\n", i);
        for (j = 0; j < m; j++) {
            printf("\t'%d':", j + 1);
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\n\nEnter no. of AVAILABLE resources\n");
    for (j = 0; j < m; j++) {
        printf("\t'%d':", j + 1);
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    printf("\n\nNEED MATRIX:\t");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\t", i);
        for (j = 0; j < m; j++) {
            printf("%d  ", need[i][j]);
        }
    }
    printf("\n\nSAFETY SEQUENCE:\t");
    safety();
}

/* OUTPUT

Enter no. of processes:  5

Enter no. of resource instances:         4


Enter MAXIMUM resources requirement of processes
Process 0:
        '1':3
        '2':2
        '3':5
        '4':2

Process 1:
        '1':3
        '2':4
        '3':1
        '4':2

Process 2:
        '1':2
        '2':7
        '3':7
        '4':3

Process 3:
        '1':5
        '2':5
        '3':0
        '4':7

Process 4:
        '1':6
        '2':2
        '3':1
        '4':4


Enter ALLOCATED resources requirement of processes
Process 0:
        '1':1
        '2':0
        '3':2
        '4':2

Process 1:
        '1':0
        '2':2
        '3':1
        '4':2

Process 2:
        '1':2
        '2':4
        '3':5
        '4':0

Process 3:
        '1':3
        '2':0
        '3':0
        '4':0

Process 4:
        '1':4
        '2':2
        '3':1
        '4':3


Enter no. of AVAILABLE resources
        '1':3
        '2':0
        '3':0
        '4':1


NEED MATRIX:
Process 0:      2  2  3  0
Process 1:      3  2  0  0
Process 2:      0  3  2  3
Process 3:      2  5  0  7
Process 4:      2  0  0  1

SAFETY SEQUENCE:        P4      P1      P2      P0      P3

*/
