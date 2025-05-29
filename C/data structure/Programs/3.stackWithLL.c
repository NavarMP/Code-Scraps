//3. Stack using Linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *ptr;
};

struct node *top = NULL;
int count = 0;

void create();
void push(int data);
void pop();
void display();
void stack_count();
void destroy();
void empty();
int topElement();

int main() {
    printf ("Create your stack and perform operations\n");

    int choice, data;
    
    create();

    printf ("\nThe Stack is now Empty.\n");

    while (1) {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Top");
        printf("\n 4 - Empty");
        printf("\n 5 - Exit");
        printf("\n 6 - Display");
        printf("\n 7 - Stack Count");
        printf("\n 8 - Destroy stack\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (top == NULL) {
                    printf("No elements in stack");
                } else {
                    int e = topElement();
                    printf("\n Top element: %d", e);
                }
                break;
            case 4:
                empty();
                break;
            case 5:
                exit(0);
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
                printf(" Wrong choice, Please enter correct choice.");
                break;
        }
    }

    return 0;
}

void create() {
    top = NULL;
}

void stack_count() {
    printf("\n No. of elements in stack: %d", count);
}

void push(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->ptr = top;
    top = temp;
    count++;
}

void display() {
    struct node *top1 = top;
    if (top1 == NULL) {
        printf("Stack is empty");
        return;
    }
    while (top1 != NULL) {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
    printf("\n");
}

void pop() {
    if (top == NULL) {
        printf("\n Error: Stack underflow");
        return;
    }
    struct node *temp = top;
    printf("\n Popped value: %d", top->info);
    top = top->ptr;
    free(temp);
    count--;
}

int topElement() {
    return top->info;
}

void empty() {
    if (top == NULL) {
        printf("\n Stack is empty");
    } else {
        printf("\n Stack is not empty with %d elements", count);
    }
}

void destroy() {
    struct node *temp;
    while (top != NULL) {
        temp = top;
        top = top->ptr;
        free(temp);
    }
    printf("\n All stack elements destroyed");
    count = 0;
}