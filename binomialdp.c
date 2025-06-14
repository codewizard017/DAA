#include<stdio.h>
#include<time.h>
 
int binomial(int n, int k)
{
    int c[n+1][k+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }  
    }
    printf("Binomial Solution Table:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return c[n][k];
}

int main()
{
    clock_t start, end;
    int n,k;
    printf("Enter the value of n:");
    scanf("%d", &n);
    if(n<0)
    {
        printf("Error: n must be a non-negative integer\n");
        return -1;
    }
    printf("Enter the value of k:");
    scanf("%d", &k);
    if(k<0||k>n)
    {
        printf("Error:k must satisfy 0<=k<=n\n");
        return -1;
    }
    start=clock();
    int r=binomial(n,k);
    end=clock();
    printf("%dC%d=%d\n",n,k,r);
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time:%f seconds\n", total_t);
    return 0;
}