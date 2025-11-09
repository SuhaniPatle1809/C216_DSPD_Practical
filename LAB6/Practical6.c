#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else if(value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        printf("Duplicate not allowed.\n");
    }
    return root;
}

void search(struct node* root, int key) {
    if(root == NULL) {
        printf("Not found\n");
        return;
    }
    if(root->data == key) {
        printf("Found\n");
    }
    else if(key < root->data) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

int isLeaf(struct node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

struct node* deleteLeaf(struct node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(key < root->data) {
        root->left = deleteLeaf(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteLeaf(root->right, key);
    }
    else {
        if(isLeaf(root)) {
            printf("Deleted leaf node: %d\n", root->data);
            free(root);
            return NULL;
        }
        else {
            printf("Node is not a leaf, cannot delete.\n");
        }
    }
    return root;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;
    
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf node from BST\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
                
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 4:
                printf("Exit\n");
                exit(0);
                
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}