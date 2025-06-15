#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 99999

typedef struct{
    int u,v,w;
}edge;

void bellman(edge edges[], int V, int E, int src)
{
    int d[V];
    for(int i=0;i<V;i++)
    {
        d[i]=INF;
    }
    d[src]=0;
    for(int i=1;i<=V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;
            if(d[u]!=INF && d[u]+w<d[v])
            {
                d[v]=d[u]+w;
            }
        }
    }
    for(int i=0;i<E;i++)
    {
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(d[u]!=INF && d[u]+w<d[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printf("Vertex Distance from source %d\n", src);
    for(int i=0;i<V;i++)
    {
        if(d[i]==INF)
        {
            printf("%d\t\t INF\n",i);
        }
        else{
            printf("%d\t\t %d\n",i,d[i]);
        }
    }
}

int main()
{
    clock_t start, end;
    int V, E, src;
    printf("Enter the number of vertices and edges:");
    scanf("%d%d", &V, &E);
    edge edges[E];
    printf("Enter the edges(u,v,weight):\n");
    for(int i=0;i<E;i++)
    {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    printf("Enter the source vertex:");
    scanf("%d", &src);
    start=clock();
    bellman(edges,V,E,src);
    end=clock();
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total Time:%f seconds", total_t);
    return 0;
}
