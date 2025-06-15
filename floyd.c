#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100
#define INF 9999

int dist[n][n],v,i,j,k;

void printM()
{
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(dist[i][j]==INF)
            {
                printf(" INF");
            }
            else{
                printf("%3d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd()
{
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        printf("\n After considering vertex %d\n", k);
        printM();
    }
}

int main()
{
    clock_t start,end;
    printf("Enter the number of verices:");
    scanf("%d", &v);
    printf("Enter the adjacency matrix(use 9999 for no edge):\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }
    start=clock();
    floyd();
    end=clock();
    printf("\nFinal Distance Matrix:\n");
    printM();
    printf("\n CPU Time: %.6fs\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
