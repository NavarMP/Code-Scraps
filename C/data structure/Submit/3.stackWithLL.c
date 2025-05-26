//Stack using Linked List

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Structure for a node in the linked list stack
struct node {
    int info;
    struct node *ptr;
} *top, *top1, *temp; // Global pointers for stack operations

// Function prototypes
int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();

int count = 0; // Global counter for number of elements in the stack

int main() {
    int no, ch, e;

    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Destroy stack");

    create(); // Initialize the stack

    while (1) {
        printf("\n Enter choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                push(no);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (top == NULL) {
                    printf("No elements in stack\n"); // Added newline
                } else {
                    e = topelement();
                    printf("\n Top element : %d\n", e); // Added newline
                }
                break;
            case 4:
                empty();
                break;
            case 5:
                exit(0); // Exit the program
            case 6:
                display();
                break;
            case 7:
                stack_count();
                break;
            case 8:
                destroy();
                break;
            default:
                printf(" Wrong choice, Please enter correct choice \n"); // Added newline
                break;
        }
    }
    return 0; // Although exit(0) is used, good practice to have return
}

// Function to initialize the stack (create an empty stack)
void create() {
    top = NULL;
}

// Function to display the number of elements in the stack
void stack_count() {
    printf("\n No. of elements in stack : %d\n", count); // Added newline
}

// Function to push an element onto the stack
void push(int data) {
    if (top == NULL) {
        // If stack is empty, allocate memory for the first node
        top = (struct node *)malloc(1 * sizeof(struct node));
        if (top == NULL) { // Error handling for malloc
            printf("Memory allocation failed!\n");
            return;
        }
        top->ptr = NULL;
        top->info = data;
    } else {
        // If stack is not empty, create a new node and link it to the top
        temp = (struct node *)malloc(1 * sizeof(struct node));
        if (temp == NULL) { // Error handling for malloc
            printf("Memory allocation failed!\n");
            return;
        }
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++; // Increment element count
}

// Function to display elements of the stack
void display() {
    top1 = top; // Use a temporary pointer to traverse without modifying 'top'

    if (top1 == NULL) {
        printf("Stack is empty\n"); // Added newline
        return;
    }

    printf("Stack elements: ");
    while (top1 != NULL) {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
    printf("\n"); // Added newline for cleaner output
}

// Function to pop an element from the stack
void pop() {
    top1 = top;

    if (top1 == NULL) {
        printf("\n Error : Trying to pop from empty stack\n"); // Added newline
        return;
    } else {
        top1 = top1->ptr; // Move top1 to the next node
        printf("\n Popped value : %d\n", top->info); // Print the info of the current top
        free(top); // Free the memory of the previous top node
        top = top1; // Update top to the new top node
    }
    count--; // Decrement element count
}

// Function to get the top element of the stack without removing it
int topelement() {
    return (top->info);
}

// Function to check if the stack is empty
void empty() {
    if (top == NULL) {
        printf("\n Stack is empty\n"); // Added newline
    } else {
        printf("\n Stack is not empty with %d elements\n", count); // Added newline
    }
}

// Function to destroy the entire stack (free all allocated memory)
void destroy() {
    top1 = top;
    while (top1 != NULL) {
        top1 = top->ptr; // Move top1 to the next node before freeing current top
        free(top);       // Free the current top node
        top = top1;      // Update top to the next node
    }
    // After the loop, top should be NULL, and all nodes should be freed.
    // The following free(top1) might be redundant if top1 is already NULL.
    // However, if the last node was freed and top1 became NULL in the loop,
    // this line might cause a double-free if not handled carefully.
    // A safer way is to ensure top1 is set to NULL after the loop and avoid
    // an extra free call if the list is already empty.
    // Corrected logic:
    // free(top1); // This line is likely incorrect and potentially a double-free or error.
    // The loop correctly frees all nodes. After the loop, top and top1 will be NULL.

    top = NULL; // Ensure top is explicitly NULL after destruction
    printf("\n All stack elements destroyed\n"); // Added newline
    count = 0; // Reset count
}