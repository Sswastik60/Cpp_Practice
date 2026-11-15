#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/* Node in an adjacency list */
struct Node {
    int vertex;
    struct Node *next;
};

/* Array of adjacency-list heads */
struct Node *graph[MAX];

int visited[MAX];
int queue[MAX];
int front = 0;
int rear = 0;

/* Create a new adjacency-list node */
struct Node *createNode(int vertex) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

/* Add an edge to an undirected graph */
void addEdge(int source, int destination) {
    /* Add destination to source's list */
    struct Node *newNode = createNode(destination);
    newNode->next = graph[source];
    graph[source] = newNode;

    /* Add source to destination's list */
    newNode = createNode(source);
    newNode->next = graph[destination];
    graph[destination] = newNode;
}

/* Breadth-first search */
void bfs(int start, int n) {
    /* Reset visited array and queue */
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    front = 0;
    rear = 0;

    /* Mark the starting vertex and add it to the queue */
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        /* Remove a vertex from the queue */
        int current = queue[front++];

        printf("%d ", current);

        /* Visit its unvisited neighbours */
        struct Node *temp = graph[current];

        while (temp != NULL) {
            int neighbour = temp->vertex;

            if (visited[neighbour] == 0) {
                visited[neighbour] = 1;
                queue[rear++] = neighbour;
            }

            temp = temp->next;
        }
    }
}

/* Free the adjacency lists */
void freeGraph(int n) {
    for (int i = 0; i < n; i++) {
        struct Node *temp = graph[i];

        while (temp != NULL) {
            struct Node *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }

        graph[i] = NULL;
    }
}

int main(void) {
    int n, edges;
    int source, destination, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    /* Initialise adjacency lists */
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter each edge as: source destination\n");

    for (int i = 0; i < edges; i++) {
        if (scanf("%d %d", &source, &destination) != 2 ||
            source < 0 || source >= n ||
            destination < 0 || destination >= n) {

            printf("Invalid edge.\n");
            freeGraph(n);
            return 1;
        }

        addEdge(source, destination);
    }

    printf("Enter starting vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        freeGraph(n);
        return 1;
    }

    printf("BFS traversal: ");
    bfs(start, n);
    printf("\n");

    freeGraph(n);
    return 0;
}