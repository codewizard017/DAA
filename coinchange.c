#include<stdio.h>
#include<time.h>
#define max 50

void sort(int a[max], int indices[max], int n)
{
    int i, j, t, tindex;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                tindex=indices[j];
                indices[j]=indices[j+1];
                indices[j+1]=tindex;
            }
        }
    }
}

void findmincoins(int coins[], int n, int v, int indices[])
{
    int i, count;
    int r[max]={0};
    sort(coins, indices, n);
    for(i=0;i<n;i++)
    {
        if(coins[i]<=v)
        {
            count=v/coins[i];
            r[i]=count;
            v%=coins[i];
        }
    }
    if(v!=0)
    {
        printf("Not Possible to reach the amount");
    }
    else{
        int result[max]={0};
        for(i=0;i<n;i++)
        {
            result[indices[i]]=r[i];
        }
        for(i=0;i<n;i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main()
{
    clock_t start, end;
    int coins[max], n, v, indices[max];
    printf("Enter the number of denominations:");
    scanf("%d", &n);
    printf("Enter the denominations:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &coins[i]);
        indices[i]=i;
    }
    printf("Enter the amount:");
    scanf("%d", &v);
    start=clock();
    findmincoins(coins,n,v,indices);
    end=clock();
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time: %f seconds", total_t);
    return 0;
}