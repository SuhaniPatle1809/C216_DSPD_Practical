#include<stdio.h>  
#define MAX 5  
char queue[MAX];  
int front = -1, rear = -1;  

void insert()  
{
    char ele;
    if (rear == MAX - 1)  
    {
        printf("Queue Overflow ! \n");  
    }
    else {
        printf("Enter a character : ");
        scanf(" %c", &ele);
        if (front == -1)  
        {
            front = 0;
        }
        rear++;
        queue[rear] = ele;
        printf("Inserted : %c\n", ele);  
    }
}

void delete() {  
    if (front == -1 || front > rear)  
    {
        printf("Queue Underflow!\n");  
    }  
    else {  
        printf("Deleted queue : %c\n", queue[front]);  
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }  
}  

void display()  
{  
    int i;  
    if (front == -1 || front > rear)  
    {
        printf("Queue is empty.\n");  
    }  
    else {  
        printf("Queue elements are: ");  
        for(i = front; i <= rear; i++)  
        {
            printf("%c ", queue[i]);  
        }  
        printf("\n");
    }  
}

int main()
{
    int ch;
    do {
        printf("\nMenu ");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exit\n");
                    break;
            default: printf("Invalid choice '\n");
        }
    } while (ch != 4);
    return 0;
}