#include <stdio.h>
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
    if (root == NULL) {
        return createNode(value);
    } 
    else if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (root->data == key) {
        printf("Element %d found in the tree.\n", key);
    } 
    else if (root->data < key) {
        search(root->right, key);
    } 
    else {
        search(root->left, key);
    }
}

int main() {
    struct node* root = NULL;
    int value, key;

    printf("Enter node values (0 to stop):\n");
    do {
        scanf("%d", &value);
        if (value != 0)
            root = insert(root, value);
    } while (value != 0);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nEnter element to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}
