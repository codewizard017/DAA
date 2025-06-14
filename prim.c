#include<stdio.h>
#include<limits.h>
#include<time.h>
#define max 100

void findmst(int cost[max][max], int V, int s, int *totalcost){
    int visited[max] ={0};
    int edges=0, min, u, v;
    visited[s]=1;
    printf("Edges in the minimum spanning tree:\n");
    while(edges<V-1)
    {
        min=INT_MAX;
        u=v=-1;
        for(int i=0;i<V;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<V;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(u!=-1 && v!=-1)
        {
            printf("(%d, %d)-> %d\n", u,v,cost[u][v]);
            *totalcost += cost[u][v];
            visited[v]=1;
            edges++;
        }
        else
        {
            printf("Graph is not connected\n");
            return;
        }
    }
}

int main()
{
    int cost[max][max], V, s, totalcost=0;
    clock_t start,end;
    printf("Enter the number of vertices:");
    scanf("%d", &V);
    printf("Enter the cost adjacent matrix:\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }
    printf("Enter starting vertex(0 to %d):", V-1);
    scanf("%d", &s);
    start=clock();
    findmst(cost,V,s,&totalcost);
    end=clock();
    printf("Total cost of minimum spanning tree:%d",totalcost);
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTotal time:%f seconds\n", total_t);
    return 0;
}