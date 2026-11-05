/* Write a C program to simulate a printer queue where tasks arrive randomly and are 
processed in order.
i. Tasks (with a document ID and name) arrive at random (simulate using 
random function or user input).
ii. Enqueue each print job.
iii. Dequeue in FIFO order to simulate printing */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int documentID;
    char documentName[100];
    struct Task* next;
};
struct Queue {
    struct Task* front;
    struct Task* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue* q, int documentID, const char* documentName) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->documentID = documentID;
    strcpy(newTask->documentName, documentName);
    newTask->next = NULL;

    if (q->rear == NULL) {
        q->front = newTask;
        q->rear = newTask;
    } else {
        q->rear->next = newTask;
        q->rear = newTask;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. No tasks to print.\n");
        return -1;
    }
    struct Task* temp = q->front;
    printf("Printing Document ID: %d, Name: %s\n", temp->documentID, temp->documentName);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return 0;
}

void peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. No tasks to peek.\n");
        return;
    }
    printf("Next Document ID: %d, Name: %s\n", q->front->documentID, q->front->documentName);
}

int main() {
    struct Queue printerQueue;
    initializeQueue(&printerQueue);

    // Simulate random task arrivals
    enqueue(&printerQueue, 1, "Document1.pdf");
    enqueue(&printerQueue, 2, "Document2.docx");
    enqueue(&printerQueue, 3, "Document3.pptx");

    // Dequeue and print tasks in FIFO order
    dequeue(&printerQueue);
    dequeue(&printerQueue);
    dequeue(&printerQueue);
    dequeue(&printerQueue); // Attempt to dequeue from an empty queue
    enqueue(&printerQueue, 3, "Document3.pptx");
    peek(&printerQueue); // Peek at the next task

    return 0;
}
