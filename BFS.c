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

/* Node for Queue */
struct QNode {
    int data;
    struct QNode* next;
};

struct QNode *front = NULL, *rear = NULL;

/* Create a new adjacency list node */
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Create a graph */
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

/* Queue operations using linked list */
void enqueue(int v) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = v;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL)
        return -1;

    int v = front->data;
    struct QNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return v;
}

/* BFS Traversal */
void BFS(struct Graph* graph, int start) {
    int i;
    int visited[20] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != NULL) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = graph->adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
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

    BFS(graph, start);

    return 0;
}
