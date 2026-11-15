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

/* Tracks which vertices have been visited */
int visited[MAX];

/* Create an adjacency-list node */
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
    /* Add destination to source's adjacency list */
    struct Node *newNode = createNode(destination);
    newNode->next = graph[source];
    graph[source] = newNode;

    /* Add source to destination's adjacency list */
    newNode = createNode(source);
    newNode->next = graph[destination];
    graph[destination] = newNode;
}

/* Recursive depth-first search */
void dfs(int vertex) {
    /* Mark and print the current vertex */
    visited[vertex] = 1;
    printf("%d ", vertex);

    /* Go through the current vertex's neighbours */
    struct Node *temp = graph[vertex];

    while (temp != NULL) {
        int neighbour = temp->vertex;

        if (visited[neighbour] == 0) {
            dfs(neighbour);
        }

        temp = temp->next;
    }
}

/* Free all adjacency-list nodes */
void freeGraph(int n) {
    for (int i = 0; i < n; i++) {
        struct Node *temp = graph[i];

        while (temp != NULL) {
            struct Node *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
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

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        visited[i] = 0;
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

    printf("DFS traversal: ");
    dfs(start);
    printf("\n");

    freeGraph(n);
    return 0;
}