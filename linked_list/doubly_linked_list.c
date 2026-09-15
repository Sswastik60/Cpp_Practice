#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addAtEnd(struct node *head, int data)
{
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return head;
    }
    ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

void print_data(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head= addToEmpty(head, 10);
    addAtEnd(head, 20);
    print_data(head);
    return 0;
}