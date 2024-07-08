#include <stdio.h>
#include <stdlib.h>

// Global variables
int n, m, max[20][20], alloc[20][20], need[20][20], avail[20], finish[20], count = 0;

// Function to check for a safe sequence using Banker's Algorithm
void safety() {
    int i, j, k;
    int progress, iterationCount = 0;

    while (count < n) { // Continue until all processes are accounted for
        progress = 0; // Reset progress for the current iteration

        for (i = 0; i < n; i++) { // Iterate over all processes
            if (finish[i] == 0) { // Check if the process has not finished
                int canAllocate = 1;

                // Check if the process can be allocated the resources it needs
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) { // If resources can be allocated
                    for (k = 0; k < m; k++) {
                        avail[k] += alloc[i][k]; // Release the resources back to available pool
                    }
                    finish[i] = 1; // Mark the process as finished
                    printf("P%d\t", i); // Print the process in the safe sequence
                    count++; // Increment the count of finished processes
                    progress = 1; // Indicate that progress was made in this iteration
                }
            }
        }

        if (!progress) { // If no progress was made in this iteration
            iterationCount++; // Increment the no-progress iteration count
            if (iterationCount > n) { // If we've iterated over all processes without progress
                printf("\nNo safe sequence exists.\n");
                return;
            }
        } else {
            iterationCount = 0; // Reset iteration count if progress was made
        }
    }
}

int main() {
    int i, j;

    // Input number of processes
    printf("\nEnter number of processes:\t");
    scanf("%d", &n);

    // Input number of resource instances
    printf("\nEnter number of resource instances:\t");
    scanf("%d", &m);

    // Input maximum resource requirements for each process
    printf("\n\nEnter maximum resources requirement of processes\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\t\n", i);
        for (j = 0; j < m; j++) {
            printf("\tResource %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    // Input allocated resources for each process and calculate the need matrix
    printf("\n\nEnter allocated resources of processes\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\t\n", i);
        for (j = 0; j < m; j++) {
            printf("\tResource %d: ", j + 1);
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j]; // Calculate need as max - alloc
        }
    }

    // Input available resources
    printf("\n\nEnter available resources\n");
    for (j = 0; j < m; j++) {
        printf("\tResource %d: ", j + 1);
        scanf("%d", &avail[j]);
    }

    // Initialize all processes as not finished
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Print the need matrix
    printf("\n\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d: ", i);
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
    }

    // Calculate and print the safety sequence
    printf("\n\nSafety Sequence:\t");
    safety();
    printf("\n");

    return 0;
}

/* OUTPUT

Enter number of processes:      3

Enter number of resource instances:     2


Enter maximum resources requirement of processes

Process 0:
        Resource 1: 8
        Resource 2: 5

Process 1:
        Resource 1: 6
        Resource 2: 4

Process 2:
        Resource 1: 7
        Resource 2: 3


Enter allocated resources of processes

Process 0:
        Resource 1: 5
        Resource 2: 4

Process 1:
        Resource 1: 3
        Resource 2: 3

Process 2:
        Resource 1: 7 
        Resource 2: 0


Enter available resources
        Resource 1: 4
        Resource 2: 4


Need Matrix:

Process 0: 3 1
Process 1: 3 1
Process 2: 0 3

Safety Sequence:        P0      P1      P2

*/
