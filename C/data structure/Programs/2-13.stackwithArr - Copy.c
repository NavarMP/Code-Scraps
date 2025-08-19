//2. 13. Stack using array

#include <stdio.h>

#define MAX_SIZE 100

void push(int stack[], int *top, int n);
void pop(int stack[], int *top);
void display(int stack[], int top);
int main() {
    printf ("Create stack using array\n");
    
    int stack[MAX_SIZE], top = -1, choice, n;

    printf("\nEnter the size of STACK (MAX = %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("\nError: Stack size cannot exceed %d\n", MAX_SIZE);
        return 1;
    }

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1. PUSH\n\t 2. POP\n\t 3. DISPLAY\n\t 4. EXIT");

    do {
        printf("\n Choose an options: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, n);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("\n\t EXIT POINT");
                break;
            default:
                printf("\n\t Please Enter a valid choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

void push(int stack[], int *top, int n) {
    if (*top >= n - 1) {
        printf("\n\tStack overflow");
    } else {
        printf(" Enter a value to be pushed: ");
        int x;
        scanf("%d", &x);
        (*top)++;
        stack[*top] = x;
    }
}

void pop(int stack[], int *top) {
    if (*top <= -1) {
        printf("\n\t Stack underflow");
    } else {
        printf("\n\t The popped element is %d", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int top) {
    if (top >= 0) {
        printf("\n The elements in STACK \n");
        for (int i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
        printf("\n Press Next Choice");
    } else {
        printf("\n The stack is empty");
    }
}