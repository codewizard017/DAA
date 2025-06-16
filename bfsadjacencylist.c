#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 99999
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX][MAX], color[MAX], parent[MAX], queue[MAX], front = -1, rear = -1, traversal[MAX], traversalIndex = 0, numVertices;

void enqueue(int v) 
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() 
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isQueueEmpty() 
{
    return front == -1 || front > rear;
}

// Recursively print path from source to vertex v
void printPath(int v) 
{
    if (parent[v] == -1) 
	{
        printf("%d", v);
        return;
    }
    printPath(parent[v]);
    printf(" -> %d", v);
}

// BFS Algorithm with real-time path printing
void BFS(int start) 
{
    int i, v;
    // Initialize all vertices
    for (i = 0; i < numVertices; i++) 
	{
        color[i] = WHITE;
        parent[i] = -1;
    }
    // Start BFS
    front = rear = -1;
    enqueue(start);
    color[start] = GRAY;
    printf("\nBFS Traversal Paths:\n");
    while (!isQueueEmpty()) 
	{
        int u = dequeue();
        traversal[traversalIndex++] = u;
        // Print the path from start to current node u
        printPath(u);
        printf("\n");
        for (v = 0; v < numVertices; v++) 
		{
            if (graph[u][v] == 1 && color[v] == WHITE) 
			{
                color[v] = GRAY;
                parent[v] = u;
                enqueue(v);
            }
        }
        color[u] = BLACK;
    }
}
// Main Function
int main() {
    int i, u, v,j, start;
    clock_t s, e;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    // Initialize graph
    for (i = 0; i < numVertices; i++)
        for (j = 0; j < numVertices; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v). Enter -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1)
            break;
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }
    printf("Enter start vertex: ");
    scanf("%d", &start);
    s = clock();
    BFS(start);
    e = clock();
    double t = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("\nCPU time used: %f seconds\n", t);
    return 0;
}
