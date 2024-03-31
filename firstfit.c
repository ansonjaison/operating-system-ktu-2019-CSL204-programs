#include<stdio.h>

struct process
{
    int pid, psize, alloc, bnum, bx;
} p[20];

struct block
{
    int bnum, bsize;
} b[20];

void main()
{
    int n, m, i, j, rem;

    printf("\nEnter the number of Memory Blocks:\t");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("Memory Block %d :\n\tEnter the Block Number:\t", i + 1);
        scanf("%d", &b[i].bnum);
        printf("\tEnter the Block Size:\t");
        scanf("%d", &b[i].bsize);
    }

    printf("\nEnter the number of processes:\t");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Process %d :\n\tEnter the Process Id:\t", i + 1);
        scanf("%d", &p[i].pid);
        printf("\tEnter the Process Size:\t");
        scanf("%d", &p[i].psize);
        p[i].alloc = 0;
    }

    i = 0;
    j = 0;

    //first fit  i -> process  j -> block
    while (i < n)
    {
        if (p[i].alloc == 0)
        {
            for (j = 0; j < m; j++)
            {
                if (p[i].psize <= b[j].bsize)
                {
                    p[i].alloc = 1;
                    p[i].bnum = b[j].bnum;
                    b[j].bsize = b[j].bsize - p[i].psize;
                    p[i].bx = j;
                    break;
                }
            }
        }
        i++;
    }

    printf("\n-------------------------------------------------------------------");
    printf("\nPROCESS ID\tPROCESS SIZE\tBLOCK NUMBER\tFREE SPACE\n");
    printf("\n-------------------------------------------------------------------");

    for (i = 0; i < n; i++)
    {
        if (p[i].alloc == 1)
            printf("\n%d\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].psize, p[i].bnum, b[p[i].bx].bsize);
        else
            printf("\n%d\t\t%d\t\t-\t\t-\t\t [NOT ALLOCATED]", p[i].pid, p[i].psize);
    }
    printf("\n");
}
