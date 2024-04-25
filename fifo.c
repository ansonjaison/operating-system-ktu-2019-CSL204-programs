#include <stdio.h>

struct frames
{
    int value, status;
} frame[20];

int main()
{
    int n, len, i, j = 0, missc = 0, hitc = 0, refs[30];

    printf("\nEnter no of frames:\t");
    scanf("%d", &n);
    printf("\nEnter the length of Reference String:\t");
    scanf("%d", &len);
    printf("\nEnter the Reference String:\t");
    for (i = 0; i < len; i++)
        scanf("%d", &refs[i]);

    for (i = 0; i < n; i++)
    {
        frame[i].value = -1;
        frame[i].status = 0;
    }

    printf("\nReference String :\t");
    for (i = 0; i < len; i++)
        printf("%d ", refs[i]);
    printf("\n\n");

    for (i = 0; i < len; i++)
    {
        int flag = 0, k;
        for (k = 0; k < n; k++)
        {
            if (refs[i] == frame[k].value)
            {
                flag = 1;
                hitc++;
                break;
            }
        }

        if (flag == 0) // miss case
        {
            int m;
            frame[j].value = refs[i];
            j = (j + 1) % n; // move to the next frame in a circular manner
            missc++;
        }

        printf("Frame:\t");
        for (k = 0; k < n; k++)
            printf("%d\t", frame[k].value);

        if (flag == 0)
            printf("Miss %d\n", missc);
        else
            printf("Hit %d\n", hitc);
    }

    printf("\n\nNo of Misses = %d", missc);
    printf("\n\nNo of Hits = %d\n", hitc);

    return 0;
}

/* OUTPUT

Enter no of frames:     3

Enter the length of Reference String:   20 

Enter the Reference String:     1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

Reference String :      1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

Frame:  1       -1      -1      Miss 1
Frame:  1       2       -1      Miss 2
Frame:  1       2       3       Miss 3
Frame:  4       2       3       Miss 4
Frame:  4       2       3       Hit 1
Frame:  4       1       3       Miss 5
Frame:  4       1       5       Miss 6
Frame:  6       1       5       Miss 7
Frame:  6       2       5       Miss 8
Frame:  6       2       1       Miss 9
Frame:  6       2       1       Hit 2
Frame:  3       2       1       Miss 10
Frame:  3       7       1       Miss 11
Frame:  3       7       6       Miss 12
Frame:  3       7       6       Hit 3
Frame:  2       7       6       Miss 13
Frame:  2       1       6       Miss 14
Frame:  2       1       6       Hit 4
Frame:  2       1       3       Miss 15
Frame:  6       1       3       Miss 16


No of Misses = 16

No of Hits = 4

*/
