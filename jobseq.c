#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct job{
    int d;
    int p;
}job;

void bubble(job jobs[], int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(jobs[j].p<jobs[j+1].p)
            {
                job temp= jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
}

int deadline(job jobs[], int n)
{
    int maxd = jobs[0].d;
    for(int i=1;i<n;i++)
    {
        if(jobs[i].d>maxd)
        {
            maxd=jobs[i].d;
        }
    }
    return maxd;
}

void jobseq(job jobs[], int n)
{
    bubble(jobs,n);
    int maxd=deadline(jobs,n);
    int slot[maxd], jobindex[maxd];
    for(int i=0;i<maxd;i++)
    {
        slot[i]=0;
        jobindex[i]=-1;
    }
    int totalp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].d-1;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                jobindex[j]=i;
                totalp+=jobs[i].p;
            }
        }
    }
    printf("Job Sequence(Profit, Deadline):");
    for(int i=0;i<maxd;i++)
    {
        if (slot[i])
        {
            printf("(%d,%d)", jobs[jobindex[i]].p, jobs[jobindex[i]].d);
        }
        else
        {
            printf("(0,0)");
        }
    }
    printf("\n");
    printf("Max Profit:%d\n", totalp);
}

int main()
{
    clock_t start, end;
    int n;
    printf("Enter the number of jobs:");
    scanf("%d", &n);
    job jobs[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter details for job %d:", i+1);
        printf("Enter Deadline and Profit:");
        scanf("%d %d", &jobs[i].d, &jobs[i].p);
    }
    start=clock();
    jobseq(jobs,n);
    end=clock();
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total Time:%f seconds\n", total_t);
    return 0;
}

