#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void parentNode(struct node* root, int target) {
    if (root == NULL) {
        return;
    }
    if ((root->left != NULL && root->left->data == target) || (root->right != NULL && root->right->data == target)) {
        printf("Parent of %d is %d\n", target, root->data);
        return;
    }
    parentNode(root->left, target);
    parentNode(root->right, target);
}

int heightOfTree(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    return height;
}

void ancestors(struct node* root, int target) {
    if (root == NULL) {
        return;
    }
    if (root->data == target) {
        return;
    }
    printf("%d ", root->data);
    if ((root->left != NULL && root->left->data == target) || (root->right != NULL && root->right->data == target)) {
        return;
    }
    ancestors(root->left, target);
    ancestors(root->right, target);
}

void leafcount(struct node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    leafcount(root->left);
    leafcount(root->right);
}

int main() {
    struct node* root = NULL;

    // Insert nodes into the binary tree
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Parent of 5: ");
    parentNode(root, 5);    

    printf("Height of the tree: %d\n", heightOfTree(root));

    printf("Ancestors of 5: ");
    ancestors(root, 5);

    printf("\n");
    printf("Leaf nodes: "); 
    leafcount(root);

    printf("\n");

    return 0;
}