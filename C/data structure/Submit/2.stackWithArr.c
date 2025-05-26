//2. Stack using Array

#include <stdio.h>

// Global variables for stack operations
int stack[100], choice, n, top, x, i;

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main() {
    top = -1; // Initialize top of the stack
    printf("\n Enter the size of STACK [MAX=100]: ");
    scanf("%d", &n);

    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1. PUSH");
    printf("\n\t 2. POP");
    printf("\n\t 3. DISPLAY");
    printf("\n\t 4. EXIT");

    do {
        printf("\n Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT\n"); // Added newline for cleaner output
                break;
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

// Function to push an element onto the stack
void push() {
    if (top >= n - 1) {
        printf("\n\tSTACK is over flow\n"); // Added newline for cleaner output
    } else {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top <= -1) {
        printf("\n\tStack is under flow\n"); // Added newline for cleaner output
    } else {
        printf("\n\tThe popped element is %d\n", stack[top]); // Added newline for cleaner output
        top--;
    }
}

// Function to display the elements of the stack
void display() {
    if (top >= 0) {
        printf("\n The elements in STACK are:\n");
        for (i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
        printf("\n Press Next Choice\n"); // Added newline for cleaner output
    } else {
        printf("\n The STACK is empty\n"); // Added newline for cleaner output
    }
}