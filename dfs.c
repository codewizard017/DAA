#include<stdio.h>
#include<time.h>
#define max 100
#define white 0
#define gray 1
#define black 2
#define nil -1

int adjM[max][max];
int color[max], d[max], pi[max], f[max], vertex, t;

void dfsvisit(int u)
{
    t++;
    d[u]=t;
    color[u]=gray;
    printf("%d ", u);
    for(int v=0;v<vertex;v++)
    {
        if(adjM[u][v]==1 && color[v]==white)
        {
            pi[v]=u;
            dfsvisit(v);
        }
    }
    color[u]=black;
    t++;
    f[u]=t;
}

void dfs()
{
    printf("DFS Traversal:");
    for(int u=0;u<vertex;u++)
    {
        if(color[u]==white)
        {
            dfsvisit(u);
        }
    }
    printf("\n");
}

void printpath(int s,int v)
{
    if(v==s)
    {
        printf("%d ", s);
    }
    else if(pi[v]==nil)
    {
        printf("No path from %d to %d exists.\n", s,v);
    }
    else{
        printpath(s,pi[v]);
        printf("->%d", v);
    }
}

int main()
{
    clock_t start, end;
    int i,j,s,e;
    printf("Enter no. of vertices:");
    scanf("%d", &vertex);
    if(vertex>max)
    {
        printf("Exceeded max vertex limit\n");
        return 1;
    }
    printf("Enter adjacency matrix:\n");
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            scanf("%d", &adjM[i][j]);
        }
    }
    start=clock();
    dfs();
    end=clock();
    printf("Enter starting node:");
    scanf("%d", &s);
    printf("Enter destination node:");
    scanf("%d", &e);
    printf("Path from %d to %d:", s,e);
    printpath(s,e);
    printf("\n");
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total Time:%f seconds\n", total_t);
    return 0;
}
