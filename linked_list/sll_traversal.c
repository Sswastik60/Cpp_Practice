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

void insert_at_position(struct node * head,int data,int position){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr ,*temp;
    ptr=head;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data=data;
    temp->next=NULL;

    for (int i=0;i<position-1;i++){
        ptr=ptr->next;
    }// reach the position where we want to insert the node

    temp->next=ptr->next;
    ptr->next=temp;
}

struct node* delete_first_node(struct node * head){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr = NULL;
    ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return head;
}

void delete_last_node(struct node * head){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr = NULL;
    ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;

}

void delete_at_position(struct node * head,int position){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *temp = NULL;
    temp=head;
    for (int i=0;i<position-1;i++){
        temp=temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next=temp2->next;
    free(temp2);
    temp2=NULL;
}

void delete_list(struct node * head){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *ptr = NULL;
    ptr=head;
    while(ptr!=NULL){
        struct node *temp = ptr;
        ptr=ptr->next;
        free(temp);
        temp=NULL;
    }
}

struct node* reverse_list(struct node * head){
    if(head==NULL){
        printf("Empty list");
    }
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while(current!=NULL){
        struct node *next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
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

    //inserting node at end of sll
    insert_at_end(head,40);

    //inserting at the beginning of sll
    head = insert_at_beginning(head, 50);

    insert_at_position(head, 60, 2);

    //deleting first node
    head = delete_first_node(head);

    //deleting last node
    delete_last_node(head);
    
    //deleting node at position
    delete_at_position(head, 1);

    //count number of nodes
    count_nodes(head);

    //printing the data of linked list before reversing
    printf("before reversing:\n");
    print_data(head);
    

    //reverse the linked list
    head = reverse_list(head);

    //printing the data of linked list after reversing
    printf("after reversing:\n");
    print_data(head);
    //all single linked list operations are done 
    return 0;
}