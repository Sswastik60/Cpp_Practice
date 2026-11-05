/* Create a queue of structures (e.g., queue of patients with name, age, and priority). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[100];
    int age;
    int priority;
    struct Patient* next;
};

struct Queue {
    struct Patient* front;
    struct Patient* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue* q, const char* name, int age, int priority) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->priority = priority;
    newPatient->next = NULL;

    if (q->rear == NULL) {
        q->front = newPatient;
        q->rear = newPatient;
    } else {
        q->rear->next = newPatient;
        q->rear = newPatient;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. No patients to process.\n");
        return -1;
    }
    struct Patient* temp = q->front;
    printf("Processing Patient: Name: %s, Age: %d, Priority: %d\n", temp->name, temp->age, temp->priority);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return 0;
}

void peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. No patients to peek.\n");
        return;
    }
    printf("Next Patient: Name: %s, Age: %d, Priority: %d\n", q->front->name, q->front->age, q->front->priority);
}

int main() {
    struct Queue patientQueue;
    initializeQueue(&patientQueue);

    enqueue(&patientQueue, "Alice", 30, 2);
    enqueue(&patientQueue, "Bob", 25, 1);
    enqueue(&patientQueue, "Charlie", 40, 3);

    peek(&patientQueue);

    dequeue(&patientQueue);
    peek(&patientQueue);

    dequeue(&patientQueue);
    dequeue(&patientQueue);
    dequeue(&patientQueue); // Attempt to dequeue from an empty queue

    return 0;
}