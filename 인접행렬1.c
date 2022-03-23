#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
int n;
int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g)
{
int r, c;
g->n = 0;
for (r = 0; r<MAX_VERTICES; r++)
for (c = 0; c<MAX_VERTICES; c++)
g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
if (((g->n) + 1) > MAX_VERTICES) {
fprintf(stderr, "그래프: 정점의 개수 초과");
return;
}
g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
if (start >= g->n || end >= g->n) {
fprintf(stderr, "그래프: 정점 번호 오류");
return;
}
g->adj_mat[start][end] = 1;
g->adj_mat[end][start] = 1;
}

void print_vertex(GraphType* g, int n){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      printf("%2d", g->adj_mat[i][j]);
    }
    printf("\n");
  }
}

void print_visited(int a[], int n){
  int i=0;
  printf("visited의 방문 결과 -> ");
  while (i < n){
    printf("%d ", a[i++]);
  }
  printf("\n");
}

void dfs_mat(GraphType* g, int v)
{
  printf(" 깊이 우선 탐색 %d 호출입니다.\n", v);
int w;
visited[v] = TRUE;
  print_visited(visited, 5);
printf("정점 %d  \n", v);
for (w = 0; w<g->n; w++)
if (g->adj_mat[v][w] && !visited[w])
dfs_mat(g, w);
}
int main(void)
{
GraphType *g;
g = (GraphType *)malloc(sizeof(GraphType));
init(g);
for (int i = 0; i<5; i++)
insert_vertex(g, i);

insert_edge(g, 0, 1);
insert_edge(g, 0, 3);
insert_edge(g, 1, 2);
insert_edge(g, 1, 4);
insert_edge(g, 2, 3);
insert_edge(g, 3, 4);

  printf("인접 행렬의 결과.\n");
  print_vertex(g, 5);
  printf("\n");
  
printf("깊이 우선 탐색(dfs)\n");
dfs_mat(g, 0);
printf("\n");
free(g);
return 0;
}
