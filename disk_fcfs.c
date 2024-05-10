#include <stdio.h>
#include <stdlib.h>

int seeks = 0, req[30];

void main() {
    int i, n, head, cylinders;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the number of Cylinders: ");
    scanf("%d", &cylinders);

    printf("Enter the initial position of head: ");
    scanf("%d", &head);

    printf("Enter the Requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    seeks += abs(req[0] - head);

    for (i = 1; i < n; i++) {
        seeks += abs(req[i] - req[i - 1]);
    }

    printf("Total No. of Seeks = %d", seeks);
}
