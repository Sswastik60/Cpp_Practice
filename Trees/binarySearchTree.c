#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createBST(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node *root,int data){
    if(root==NULL){
        return createBST(data);
    }
    if(data<root->data){
        root->left=insertNode(root->left,data);
    }
    else if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    else{
        printf("Duplicate data not allowed in BST\n");
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void searchNode(struct Node* root,int data){
    if (root == NULL) {
        printf("Data %d not found in the BST\n", data);
        return;
    }
    else if (data < root->data) {
        searchNode(root->left, data);
    }
    else if (data > root->data) {
        searchNode(root->right, data);
    }
    else {
        printf("Data %d found in the BST\n", data);
    }
}

void deleteNode(struct Node* root,int data){
    if (root == NULL){
        printf("Data %d not found in the BST\n", data);
        return;
    }
    else if (data <root->data){
        deleteNode(root->left,data);
    }
    else if(data >root->data){
        deleteNode(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            struct Node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct Node* temp=root;
            root=root->left;
            free(temp);
        }
        else{
            struct Node* temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            deleteNode(root->right,temp->data);
        }
        //explaination : This case handles the deletion of a node with two children.
        // It finds the inorder successor (smallest node in the right subtree) and
        // replaces the node's data with the successor's data, then deletes the successor.
    }
}

void minimumValueNode(struct Node* root) {
    struct Node* current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    printf("Minimum value in the BST is: %d\n", current->data);
}

void maximumValueNode(struct Node* root) {
    struct Node* current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    printf("Maximum value in the BST is: %d\n", current->data);
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    searchNode(root, 40);
    searchNode(root, 100);
    minimumValueNode(root);
    maximumValueNode(root);
    return 0;
}