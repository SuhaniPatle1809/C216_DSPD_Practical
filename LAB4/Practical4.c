#include<stdio.h>  
#include<stdlib.h>  

struct Node  
{
    int data;  
    struct Node *next;  
};  

struct Node* createNode(int data)  
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)  
    {
        printf("Memory allocation failed\n");  
        exit(1);  
    }  
    newNode->data = data;  
    newNode->next = NULL;  
    return newNode;  
}  

void insertEnd(struct Node** head, int data)  
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)  
    {
        *head = newNode;  
    }  
    else  
    {
        struct Node* current = *head;  
        while (current->next != NULL)  
        {
            current = current->next;  
        }  
        current->next = newNode;  
    }  
}  

void printList(struct Node* head)  
{
    struct Node* current = head;  
    while (current != NULL)  
    {
        printf("%d => ", current->data);  
        current = current->next;  
    }  
    printf("NULL \n");  
}  

int countNodes(struct Node* head)  
{
    int count = 0;  
    struct Node* current = head;  
    while (current != NULL)  
    {
        count++;  
        current = current->next;  
    }  
    return count;  
}  

void freeList(struct Node* head)  
{
    struct Node* current = head;  
    while (current != NULL)  
    {
        struct Node* temp = current;  
        current = current->next;  
        free(temp);  
    }  
}  

int main()  
{
    struct Node *head = NULL;  
    int ele;  
    printf("Enter integer elements (enter 0 to stop): ");  
    while (1)  
    {
        scanf("%d", &ele);  
        if (ele == 0)  
        {
            break;  
        }  
        insertEnd(&head, ele);  
    }  
    printf("Linked list: ");  
    printList(head);  
    int nodeCount = countNodes(head);  
    printf("Number of nodes in the list: %d\n", nodeCount);  
    
    freeList(head);  
    return 0;  
}