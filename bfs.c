#include<stdio.h>
#include<time.h>
#define max 50

int adjM[max][max];
int v[max], q[max], p[max];
int f=-1, r=-1;

void enqueue(int value)
{
    if(r==max-1)
        return;
    if(f==-1)
        f=0;
    q[++r]=value;
}

int dequeue()
{
    if(f==-1||f>r)
        return -1;
    return q[f++];
}

int isEmpty()
{
    return f==-1||f>r;
}

void bfs(int n, int svertex, int dvertex)
{
    for(int i=0;i<n;i++)
    {
        v[i]=0;
        p[i]=-1;
    }
    v[svertex]=1;
    enqueue(svertex);
    printf("BFS Traversal:");
    while(!isEmpty())
    {
        int current=dequeue();
        printf("%d ", current);
        if(current==dvertex)
        {
            printf("\nDestination %d reached!\n", dvertex);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(adjM[current][i]==1 && !v[i])
            {
                v[i]=1;
                p[i]=current;
                enqueue(i);
            }
        }
    }
    printf("\n Destination %d not reachable\n", dvertex);
}

void printpath(int *p, int s, int v)
{
    if(v==s)
    {
        printf("%d ", s);
    }
    else if(p[v]==-1)
    {
        printf("No path from %d to %d exists\n", s,v);
    }
    else
    {
        printpath(p,s,p[v]);
        printf("%d ", v);
    }
}

int main()
{
    clock_t start, end;
    int n,s,dest;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &adjM[i][j]);
        }
    }
    while(getchar()!='\n');
    printf("Enter starting vertex:");
    scanf("%d", &s);
    if(s<0||s>=n)
    {
        printf("Error:Invalid Starting Vertex. Enter a value between 0 and %d\n", n-1);
        return 1;
    }
    printf("Enter destination vertex: ");
    scanf("%d", &dest);
    
    if (dest < 0 || dest >= n) {
        printf("Error: Invalid destination vertex. Enter a value between 0 and %d.\n", n - 1);
        return 1;
    }
    start=clock();
    bfs(n,s,dest);
    end=clock();
    printf("Shortest path from %d to %d:", s,dest);
    printpath(p,s,dest);
    printf("\n");
    double total_t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total Time:%f seconds\n", total_t);
    return 0;
}