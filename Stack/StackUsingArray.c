#include "Stack.h"
#include <stdio.h>


int main() {
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    Stack* stack = createStack(capacity);
    if (stack == NULL) {
        printf("Error while creating the stack\n");
        return 1;
    }

    while (true) {
        printf("\nMenu:\n");
        printf("1. Put (Push)\n");
        printf("2. Pop\n");
        printf("3. Check if Full\n");
        printf("4. Check if Empty\n");
        printf("5. Search\n");
        printf("6. Top Element\n");
        printf("7. View Stack\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter a number to push: ");
                scanf("%d", &num);
                if (put(stack, num))
                    printf("Element pushed successfully\n");
                else
                    printf("Stack is full. Cannot push element\n");
                break;
            }

            case 2: {
                Dtype result = pop(stack);
                if (result.bool_v)
                    printf("Popped element: %d\n", result.int_v);
                else
                    printf("Stack is empty. Cannot pop element\n");
                break;
            }

            case 3: {
                if (isFull(stack))
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            }

            case 4: {
                if (isEmpty(stack))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            }

            case 5: {
                int num;
                printf("Enter a number to search: ");
                scanf("%d", &num);
                Dtype result = search(stack, num);
                if (result.bool_v)
                    printf("Element found at index: %d\n", result.int_v);
                else
                    printf("Element not found in stack\n");
                break;
            }

            case 6: {
                Dtype result = top(stack);
                if (result.bool_v)
                    printf("Top element: %d\n", result.int_v);
                else
                    printf("Stack is empty. No top element\n");
                break;
            }
            case 7:{
                printf("\n");
                int *temp;
                for(int i = 0; i < (stack->top)+1; i++)
                {
                    temp = select(stack, i);
                    if(*temp == NULL)
                    {
                        printf("Error while selecting element");
                        break;
                    }
                    printf("%d  ",temp);
                }
                printf("\n");
                break;
            }
            case 8: {
                printf("Exiting...\n");
                destroyStack(stack);
                return 0;
            }

            default:
                printf("Invalid choice. Please try again\n");
        }
    }

    return 0;
}
