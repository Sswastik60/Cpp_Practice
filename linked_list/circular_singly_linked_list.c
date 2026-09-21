#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *circularsll(int data){
    struct node *temp =malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node * add_at_beginning(struct node *tail,int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}//here the tail never changes because we are adding the new node at the beginning of the list, so the tail remains the same.
 
struct node * add_at_end(struct node *tail,int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
}//here the tail changes because we are adding the new node at the end of the list, so the tail now points to the new node.

struct node * insert_at_position(struct node *tail,int data,int pos){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    struct node *p = tail;
    while(pos>1){
        p = p->next;
        pos--;
    }
    newNode->next = p->next;
    p->next = newNode;
    return tail;
}//here the tail never changes because we are adding the new node at a specific position in the list, so the tail remains the same.
 
struct node * delete_at_beginning(struct node *tail){
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    return tail;
}//here the tail never changes because we are deleting the first node of the list, so the tail remains the same.

struct node * delete_at_end(struct node *tail){
    struct node *temp = tail->next;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}//here the tail changes because we are deleting the last node of the list, so the tail now points to the second last node.

struct node * delete_at_position(struct node *tail,int pos){
    struct node *temp = tail->next;
    struct node *p = tail;
    while(pos>1){
        p = temp;
        temp = temp->next;
        pos--;
    }
    p->next = temp->next;
    free(temp);
    return tail;
}//here the tail never changes because we are deleting a node at a specific position in the list, so the tail remains the same.

void count_nodes(struct node *tail){
    struct node *temp = tail->next;
    int count = 0;
    if(tail == NULL){
        printf("List is empty\n");
        return;
    }
    do{
        count++;
        temp = temp->next;
    }while(temp != tail->next);
    printf("Number of nodes in the list: %d\n",count);
}

void search_node(struct node *tail,int key){
    struct node *temp = tail->next;
    int pos = 1;
    if(tail == NULL){
        printf("List is empty\n");
        return;
    }
    do{
        if(temp->data == key){
            printf("Node found at position: %d\n",pos);
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != tail->next);
    printf("Node not found\n");
}
void printcsll(struct node *tail){
    struct node *temp = tail->next;
    if(tail == NULL){
        printf("List is empty\n");
        return;
    }
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp != tail->next);
    printf("\n");
}
int main()
{
    struct node *tail;
    tail = circularsll(34);
    tail = add_at_beginning(tail, 23);
    printcsll(tail);
    tail = add_at_beginning(tail, 45);
    printcsll(tail);
    tail = add_at_end(tail, 56);
    tail = add_at_end(tail, 78);
    tail = add_at_end(tail, 90);
    printcsll(tail);
    tail = insert_at_position(tail, 60, 3);
    printcsll(tail);
    tail = delete_at_beginning(tail);
    printcsll(tail);
    tail = delete_at_end(tail);
    printcsll(tail);
    tail = delete_at_position(tail, 2);
    printcsll(tail);
    count_nodes(tail);
    search_node(tail, 56);
}