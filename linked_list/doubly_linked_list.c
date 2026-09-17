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
void add_btw_nodes(struct node *head,int data,int pos){
    struct node *temp,*temp2;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    temp = (struct node*)malloc(sizeof(struct node));
    temp2 = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    while(pos!=1){
        temp = head;
        temp=temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = temp2;
    temp2->prev = new_node;
}

struct node* delete_node_at_beginning(struct node *head, int pos)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    head = head->next;
    temp->next = NULL;
    free(temp);
    head->prev = NULL;
    return head;
}

struct node* delete_node_at_end(struct node *head)
{
    struct node *temp = head;
    struct node *temp2 = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
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
//doubly linked list continues with add_btw_nodes, delete_node_at_beginning, delete_node_at_end, and print_data functions.
int main()
{
    struct node *head = NULL;
    head= addToEmpty(head, 10);
    head = addAtEnd(head, 20);
    head = addAtEnd(head, 30);
    head = addAtEnd(head, 40);
    head = addAtEnd(head, 50);
    add_btw_nodes(head, 25, 2);
    print_data(head);
    head = delete_node_at_beginning(head, 1);
    print_data(head);
    head = delete_node_at_end(head);
    print_data(head);

    return 0;
}