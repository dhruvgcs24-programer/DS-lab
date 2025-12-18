#include <stdio.h>
#include <stdlib.h>

/* Node for adjacency list */
struct Node {
    int vertex;
    struct Node* next;
};

/* Graph structure */
struct Graph {
    int vertices;
    struct Node** adjList;
};

/* Create adjacency list node */
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Create graph */
struct Graph* createGraph(int v) {
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));
    for (i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}

/* Add edge (undirected graph) */
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

/* DFS Recursive Function */
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

/* DFS Traversal */
void DFS(struct Graph* graph, int start) {
    int visited[20] = {0};

    printf("DFS Traversal: ");
    DFSUtil(graph, start, visited);
}

int main() {
    int v, e, i, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    struct Graph* graph = createGraph(v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    DFS(graph, start);

    return 0;
}
