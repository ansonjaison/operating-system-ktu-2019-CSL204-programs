#include <stdio.h>

struct frame {
    int value;
    int count;
    int status;
};

void main() {
    int n, len, i, j = 1, missc = 0, hitc = 0, f = 0;
    printf("\nEnter no of frames:\t");
    scanf("%d", &n);
    printf("\nEnter the length of Reference String:\t");
    scanf("%d", &len);

    int refs[len];
    struct frame frame[n];

    printf("\nEnter the Reference String:\t");
    for (i = 0; i < len; i++)
        scanf("%d", &refs[i]);

    for (i = 0; i < n; i++) {
        frame[i].value = -1;
        frame[i].status = -1;
        frame[i].count = 0;
    }

    printf("\nReference String :\t");
    for (i = 0; i < len; i++)
        printf("%d  ", refs[i]);
    printf("\n\n");

    for (i = 0; i < len; i++) {
        int flag = 0;
        if (j <= n) { // frames empty case
            frame[f].value = refs[i];
            frame[f].status = 0;
            frame[f].count++;
            j++;
            missc++;
        } else { // frames not empty
            for (int k = 0; k < n; k++) {
                if (refs[i] == frame[k].value) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) { // hit case
                hitc++;
                for (int k = 0; k < n; k++) {
                    if (refs[i] == frame[k].value) {
                        frame[k].status = 1;
                        frame[k].count++;
                        break;
                    }
                }
            } else { // miss
                int min_count = frame[0].count;
                int min_index = 0;
                for (int m = 1; m < n; m++) {
                    if (frame[m].count < min_count) {
                        min_count = frame[m].count;
                        min_index = m;
                    }
                }
                frame[min_index].value = refs[i];
                frame[min_index].status = 0;
                frame[min_index].count++;
                missc++;
            }
        }
        printf("\nFrames:\n");
        for (int k = 0; k < n; k++) {
            printf("%d\t", frame[k].value);
        }

        if (frame[f].status == 0) {
            printf("\tMiss %d\n", missc);
            f = (f + 1) % n;
        } else
            printf("\tHit %d\n", hitc);
    }

    printf("\n\nNo of Misses = %d", missc);
    printf("\n\nNo of Hits = %d\n", hitc);
}

/* OUTPUT

Enter no of frames:     3

Enter the length of Reference String:   20

Enter the Reference String:     1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

Reference String :      1  2  3  4  2  1  5  6  2  1  2  3  7  6  3  2  1  2  3  6


Frames:
1       -1      -1              Miss 1

Frames:
1       2       -1              Miss 2

Frames:
1       2       3               Miss 3

Frames:
4       2       3               Miss 4

Frames:
4       2       3               Hit 1

Frames:
4       2       1               Hit 1

Frames:
5       2       1               Hit 1

Frames:
5       6       1               Miss 7

Frames:
5       6       2               Miss 8

Frames:
1       6       2               Miss 9

Frames:
1       6       2               Miss 9

Frames:
1       3       2               Hit 2

Frames:
7       3       2               Hit 2

Frames:
7       6       2               Hit 2

Frames:
7       6       3               Miss 13

Frames:
2       6       3               Miss 14

Frames:
2       1       3               Miss 15

Frames:
2       1       3               Miss 15

Frames:
2       1       3               Hit 4

Frames:
2       6       3               Hit 4


No of Misses = 16

No of Hits = 4

*/
