#include<stdio.h>
#include<stdlib.h>

int seeks = 0, req[30], order[30];

void main() {
    int i, j, n, head, cylinders, least, temp, pos;

    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);

    printf("\nEnter the number of Cylinders: ");
    scanf("%d", &cylinders);

    printf("\nEnter the initial position of head: ");
    scanf("%d", &head);

    printf("\nEnter the Requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    least = req[0];
    for(i = 0; i < n; i++) {
        if(least > req[i])
            least = req[i];
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                temp = req[j];
                req[j] = req[i];
                req[i] = temp;
            }
        }
    }

    printf("Order of Execution: ");
    for(i = 0; i < n; i++) {
        if(head < req[i]) {
            pos = i;
            break;
        }
    }

    seeks = (cylinders - head - 1) + (cylinders - 1) + (req[pos - 1]);

    for(i = pos; i < n; i++) {
        printf("%d ", req[i]);
    }

    for(i = 0; i <= pos - 1; i++) {
        printf("%d ", req[i]);
    }

    printf("\nTotal No. of Seeks = %d", seeks);
}


/* OUTPUT

Enter the number of Requests: 7

Enter the number of Cylinders: 200

Enter the initial position of head: 55

Enter the Requests: 93 176 42 148 27 14 180
Order of Execution: 93 148 176 180 14 27 42
Total No. of Seeks = 385

*/
