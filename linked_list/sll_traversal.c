#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void count_nodes(struct node *head){
    int count =0;
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr = NULL;
    ptr =head;
    while (ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    printf("%d\n",count);
}

void print_data(struct node * head){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr = NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void insert_at_end(struct node * head,int data){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr ,*temp;
    ptr=head;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data=data;
    temp->next=NULL;
    
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
}

struct node* insert_at_beginning(struct node * head,int data){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head=temp;
    return head;
}

int main(){
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head ->data =10;
    head ->next = NULL;


    struct node *current = (struct node*)malloc(sizeof(struct node));
    current ->data =20;
    current ->next = NULL;
    head->next=current;//this creates the link

    struct node *current2 = (struct node*)malloc(sizeof(struct node));
    current2 ->data =30;
    current2 ->next = NULL;
    current->next=current2;//this creates the link


    //count nodes
    count_nodes(head);
    
    //inserting node at end of sll
    insert_at_end(head,40);

    //inserting at the beginning of sll
    head = insert_at_beginning(head, 50);

    //print data of nodes
    print_data(head);
    return 0;
}