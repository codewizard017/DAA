#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX][MAX], color[MAX], parent[MAX], numVertices;

void DFS_Visit(int u, int* path, int* pathSize) 
{
	int v;
    color[u] = GRAY;  // marking node as visited
    path[(*pathSize)++] = u;  // adding node to current path
    for (v = 0; v < numVertices; v++)  // exploring all neighbors of the node u
    {
        if (graph[u][v] && color[v] == WHITE) 
        {
            printf("%d -> %d\n", u, v);  // printing the traversal edge
            DFS_Visit(v, path, pathSize);  // recurrence on the child node
        }
    }
    color[u] = BLACK;  // marking node as fully processed
    (*pathSize)--;  // backtracking, remove node from current path
}

void DFS(int start) 
{
    int path[MAX], pathSize = 0, i;
    for (i = 0; i < numVertices; i++) // resettig color and parent arrays
    {
        color[i] = WHITE;
        parent[i] = -1;
    }
    path[pathSize++] = start;// starting DFS from the given node
    DFS_Visit(start, path, &pathSize);  // starting DFS from the given node
    for (i = 0; i < numVertices; i++)   // handling disconnected components
        if (color[i] == WHITE) 
            DFS_Visit(i, path, &pathSize);
}

int main() 
{
    int i, j, u, v, start;
    clock_t s, e;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    for (i = 0; i < numVertices; i++)  // initializing graph
        for (j = 0; j < numVertices; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v). Enter -1 -1 to stop:\n");
    while (1) 
    {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1)
            break;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    s = clock();
    DFS(start);
    e = clock();
    printf("\nCPU Time: %f seconds\n", (double)(e - s) / CLOCKS_PER_SEC);
    return 0;
}
