#include <stdio.h>
#include <stdlib.h>

int graph[10][10];
int visited[10];
int queue[10];
int front = 0, rear = 0;
int n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j;
    int start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter graph matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("DFS: ");
    dfs(start);
    printf("\n");

    printf("BFS: ");
    bfs(start);
    printf("\n");

    return 0;
}
