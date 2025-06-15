#include<stdio.h>
#include<time.h>
#define maxitems 100
#define maxcapacity 1000

int *knap01(int data[][2], int n, int m , int dp[][maxcapacity+1], int ans[])
{
    int i, j, v1, v2;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                v1=dp[i-1][j];
                if(j-data[i][0]<0)
                {
                    dp[i][j]=v1;
                }
                else
                {
                    v2=data[i][1]+dp[i-1][j-data[i][0]];
                    dp[i][j]=(v1>v2)?v1:v2;
                }
            }
        }
    }
    printf("Solution Table:\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    int starti=n, startj=m;
    while(starti>0 && startj>0)
    {
        if(dp[starti][startj]==dp[starti-1][startj])
        {
            starti--;
        }
        else{
            ans[starti-1]=1;
            startj-=data[starti][0];
            starti--;
        }
    }
    return ans;
}

int main()
{
    int n, i, capacity;
    printf("Enter number of items:");
    scanf("%d", &n);
    int items[maxitems+1][2];
    int dp[maxitems+1][maxcapacity+1]={0};
    int ans[maxitems]={0};
    items[0][0]=0;
    items[0][1]=0;
    for(i=1;i<=n;i++)
    {
        printf("Enter weight and value of item %d: ", i);
        scanf("%d %d", &items[i][0], &items[i][1]);
    }
    printf("Enter capacity of the bag:");
    scanf("%d", &capacity);
    if(n>maxitems||capacity>maxcapacity)
    {
        printf("Error!\n");
        return 1;
    }
    clock_t start=clock();
    knap01(items, n, capacity, dp,ans);
    clock_t end=clock();
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Solution Vector:");
    for(i=0;i<n;i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    printf("Maximum Value=%d\n", dp[n][capacity]);
    printf("Total Time:%f seconds\n", total_t);
    return 0;
}