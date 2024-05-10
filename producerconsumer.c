#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces %d", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes %d", x);
    x--;
    ++mutex;
}

void main() {
    int ch;
    printf("Enter Buffer size:\t ");
    scanf("%d", &empty);
    printf("\nChoices:\n1. Producer\t2. Consumer\t3. Exit");
    while (1) {
        printf("\n\nEnter Choice \t:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is Full");
                break;

            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is Empty");
                break;
            case 3:
                exit(0);
                break;
        }
    }
}
