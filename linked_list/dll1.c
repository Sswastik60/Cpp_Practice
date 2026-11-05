/*3. Washing Machine Rental System Simulation
Develop a C application to simulate a washing machine rental queue using a circular doubly 
linked list.
Requirements:
i. Each user books the washing machine for a specific time.
ii. After time expires, the machine automatically passes to the next user in the 
queue.
iii. Use the circular nature of the list to model the continuous cycle of usage.
iv. Optional: simulate time using delays or counters for testing logic*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <string.h>
struct User {
    char name[50];
    int bookingTime; // in seconds
    struct User* next;
    struct User* prev;
};

int main() {
    struct User* head = NULL;
    struct User* tail = NULL;

    // Example users booking the washing machine
    struct User* user1 = (struct User*)malloc(sizeof(struct User));
    strcpy(user1->name, "Alice");
    user1->bookingTime = 5; // 5 seconds
    user1->next = user1;
    user1->prev = user1;
    head = user1;
    tail = user1;

    struct User* user2 = (struct User*)malloc(sizeof(struct User));
    strcpy(user2->name, "Bob");
    user2->bookingTime = 3; // 3 seconds
    user2->next = head;
    user2->prev = tail;
    tail->next = user2;
    head->prev = user2;
    tail = user2;

    struct User* user3 = (struct User*)malloc(sizeof(struct User));
    strcpy(user3->name, "Charlie");
    user3->bookingTime = 4; // 4 seconds
    user3->next = head;
    user3->prev = tail;
    tail->next = user3;
    head->prev = user3;
    tail = user3;

    // Simulate the washing machine rental system
    struct User* currentUser = head;
    while (1) {
        printf("Washing machine is being used by: %s for %d seconds\n", currentUser->name, currentUser->bookingTime);
        sleep(currentUser->bookingTime); // Simulate the booking time
        currentUser = currentUser->next; // Move to the next user in the circular list
        printf("Washing machine is now available for the next user.\n");
    }

    return 0;
}