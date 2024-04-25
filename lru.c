#include<stdio.h>
int n,len,r=-1,j=1,m,i,f=0,refs[40],frame[20],missc=0,status[40],hitc=0,flag=0,k,recent[40];


void main()
{
    printf("\nEnter no of frames:\t");
    scanf("%d",&n);
    printf("\nEnter the length of Reference String:\t");
    scanf("%d",&len);
    printf("\nEnter the Reference String:\t");
    for(i=0;i<len;i++)
        scanf("%d",&refs[i]);

   
    for(i=0;i<n;i++)
    {
        frame[i]=0;
        status[i]=0;
    }
   
   
    printf("\nReference String :\t");
    for(i=0;i<len;i++)
        printf("%d  ",refs[i]);
    printf("\n\n");    
   
   
   
    for(i=0;i<len;i++)
    {
        flag=0;
        if(j<=n)  // frames empty case
        {
            frame[f]= refs[i];
            status[f]=0;
            r++;
            recent[r]=refs[i];
            j++; missc++;
           
        }
       
        else  //frames not empty
        {
           
            for(k=0;k<n;k++)
            {
                if(refs[i]==frame[k])
                {
                    flag=1;
                    break;
                }
            }
           
            if(flag==1) //hit case
            {
                hitc++;
                status[f]=1;
                j++;
               
                for(m=0;m<n;m++)
                {
                    if(refs[i]==recent[m])
                        break;
                }
               
                for(k=m;k<n;k++)
                {
                    recent[k]=recent[k+1];
                }
                recent[r] = refs[i];
            }
            else //miss
            {
                for(m=0;m<n;m++)
                {
                    if(frame[m]==recent[0])
                        break;
                }
                frame[m]=refs[i];
                missc++;
                status[f]=0;
                j++;
                for(m=0;m<n;m++)
                {
                    recent[m]=recent[m+1];
                }
                recent[r] = refs[i];
            }
               
        }
        printf("Frame:\t");
        for(k=0;k<n;k++)
        {
            printf("%d\t",frame[k]);
        }
       
           
        if(status[f]==0)
        {
            printf("Miss %d\n",missc);
            if(f==n-1)
                f=0;
            else
                f++;
        }
        else
            printf("Hit %d\n",hitc);
           
           
    }  
   
    printf("\n\nNo of Misses = %d",missc);
    printf("\n\nNo of Hits = %d\n",hitc);
}

/* OUTPUT

Enter no of frames:     3

Enter the length of Reference String:   20

Enter the Reference String:     1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

Reference String :      1  2  3  4  2  1  5  6  2  1  2  3  7  6  3  2  1  2  3  6

Frame:  1       0       0       Miss 1
Frame:  1       2       0       Miss 2
Frame:  1       2       3       Miss 3
Frame:  4       2       3       Miss 4
Frame:  4       2       3       Hit 1
Frame:  4       2       1       Miss 5
Frame:  5       2       1       Miss 6
Frame:  5       6       1       Miss 7
Frame:  5       6       2       Miss 8
Frame:  1       6       2       Miss 9
Frame:  1       6       2       Hit 2
Frame:  1       3       2       Miss 10
Frame:  7       3       2       Miss 11
Frame:  7       3       6       Miss 12
Frame:  7       3       6       Hit 3
Frame:  2       3       6       Miss 13
Frame:  2       3       1       Miss 14
Frame:  2       3       1       Hit 4
Frame:  2       3       1       Hit 5
Frame:  2       3       6       Miss 15


No of Misses = 15

No of Hits = 5

*/
