#include <stdio.h>

int n;
int adj[20][20];
int visited[20];

/* DFS Function */
void DFS(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Initialize visited array */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    /* Perform DFS from vertex 0 */
    DFS(0);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The given graph is CONNECTED\n");
    else
        printf("The given graph is NOT CONNECTED\n");

    return 0;
}
