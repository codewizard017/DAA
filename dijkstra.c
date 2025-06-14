// Dijkstra's Algorithm in C

#include <stdio.h>
#include<time.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main() {
  int v;
  printf("enter the number of vertices:");
  scanf("%d", &v);
  int g[MAX][MAX];
  printf("enter the (%d * %d) adjacency matrix:\n", v,v);
  for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
          scanf("%d", &g[i][j]);
      }
  }
  int src;
  printf("enter source vertex:");
  scanf("%d",&src);
  clock_t start, end;
  start=clock();
  Dijkstra(g,v,src);
  end=clock();
  double total_t=(double)(end-start)/CLOCKS_PER_SEC;
  printf("\nProgram took %f seconds to run.\n", total_t);
  return 0;
}
