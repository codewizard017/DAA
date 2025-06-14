#include<stdio.h>
#include<time.h>

void sort(int s[], int f[], int n)
{
    int tstart, tfinish;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(f[i]>f[j])
            {
                tfinish=f[i];
                f[i]=f[j];
                f[j]=tfinish;
                tstart=s[i];
                s[i]=s[j];
                s[j]=tstart;
            }
        }
    }
}

void activityselect(int s[], int f[], int n)
{
    sort(s,f,n);
    printf("Selected Activities:\n");
    printf("Activity 1: Start Time= %d, Finish Time = %d\n", s[0],f[0]);
    int lastftime=f[0];
    int activitycount=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]>=lastftime)
        {
            activitycount++;
            printf("Activity %d: Start time = %d, Finish time = %d\n", activitycount, s[i], f[i]);
            lastftime=f[i];
        }
    }
}

int main()
{
    clock_t start, end;
    int n;
    printf("Enter the number of activities:");
    scanf("%d", &n);
    int s[n],f[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter start time and finish time for activity %d:", i+1);
        scanf("%d %d", &s[i], &f[i]);
    }
    start=clock();
    activityselect(s,f,n);
    end=clock();
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time: %f seconds", total_t);
    return 0;
}