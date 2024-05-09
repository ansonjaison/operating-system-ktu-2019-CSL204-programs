#include <stdio.h>
#include <stdlib.h>

int seeks = 0, req[30], order[30];

void main() {
    int i, j, n, head, cylinders, least, temp, pos;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the number of Cylinders: ");
    scanf("%d", &cylinders);

    printf("Enter the initial position of head: ");
    scanf("%d", &head);

    printf("Enter the Requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    least = req[0];
    for (i = 0; i < n; i++) {
        if (least > req[i])
            least = req[i];
    }

    seeks = (cylinders - least - 1) + (cylinders - head - 1);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[j];
                req[j] = req[i];
                req[i] = temp;
            }
        }
    }

    printf("Order of Execution: ");
    for (i = 0; i < n; i++) {
        if (head < req[i]) {
            pos = i;
            break;
        }
    }

    for (i = pos; i < n; i++) {
        printf("%d\t", req[i]);
    }

    for (i = pos - 1; i >= 0; i--) {
        printf("%d\t", req[i]);
    }

    printf("\nTotal No. of Seeks: %d\n", seeks);
}

/* OUTPUT

Enter the number of Requests: 7
Enter the number of Cylinders: 90
Enter the initial position of head: 53
Enter the Requests:  12 34 52 14 25 68 39
Order of Execution: 68  52      39      34      25      14      12
Total No. of Seeks: 113

*/
