#include <stdio.h>
#include <string.h>
#define SIZE 5

int main() {
    int stack[SIZE], top = -1, choice, val, i;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Push\n2. Pop\n3. Check Palindrome\n4. Overflow Demo\n5. Display Stack\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == SIZE - 1)
                    printf("Stack Overflow!\n");
                else {
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    stack[++top] = val;
                    printf("Pushed %d\n", val);
                }
                break;

            case 2:
                if (top == -1)
                    printf("Stack Underflow!\n");
                else
                    printf("Popped %d\n", stack[top--]);
                break;

            case 3: {
                char str[100], temp[100];
                int len, t = -1;

                printf("Enter String: ");
                scanf("%s", str);

                len = strlen(str);
                for (i = 0; i < len; i++)
                    temp[++t] = str[i];

                for (i = 0; i < len; i++) {
                    if (str[i] != temp[t--])
                        break;
                }

                if (i == len)
                    printf("Palindrome\n");
                else
                    printf("Not a Palindrome\n");
                break;
            }

            case 4:
                printf("Demonstrating Overflow:\n");
                for (i = 0; i < SIZE + 2; i++) {
                    if (top == SIZE - 1)
                        printf("Overflow at pushing %d\n", i);
                    else {
                        stack[++top] = i;
                        printf("Pushed %d\n", i);
                    }
                }
                break;

            case 5:
                if (top == -1)
                    printf("Stack is empty\n");
                else {
                    printf("Stack contents:\n");
                    for (i = 0; i <= top; i++)
                        printf("%d ", stack[i]);
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
