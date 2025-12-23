#include <stdio.h>
#include <stdlib.h>

int graph[10][10];
int visited[10];
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

int main() {
    int i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter graph matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            visited[i] = 0;
        }
    }

    printf("Clusters:\n");
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}
