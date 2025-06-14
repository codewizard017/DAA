#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct item{
    int w;
    int v;
    float r;
    int index;
};

void fractionalknap(int c, struct item items[], int n, float soln[]){
    for(int i=0;i<n;i++)
    {
        items[i].r = (float)items[i].v/items[i].w;
        items[i].index=i;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(items[i].r<items[j].r)
            {
                struct item temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int currentw;
        if(currentw + items[i].w <= c)
        {
            currentw += items[i].w;
            soln[items[i].index] = 1.0;
        }
        else
        {
            int remaining = c - currentw;
            soln[items[i].index] = (float)remaining/items[i].w;
            break;
        }
    }
}

int main()
{
    clock_t start, end;
    int n,c;
    printf("Enter number of items:");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack:");
    scanf("%d", &c);
    struct item items[n];
    float soln[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter value and weight for item %d:", i+1);
        scanf("%d %d", &items[i].v, &items[i].w);
    }
    start=clock();
    fractionalknap(c,items,n,soln);
    end=clock();
    double total_t= ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Solution Vector:");
    for(int i=0;i<n;i++)
    {
        printf("%.2f\t", soln[i]);
    }
    printf("\nTotal time:%f seconds", total_t);
    return 0;
}



