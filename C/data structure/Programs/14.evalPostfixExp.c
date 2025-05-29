//14. Evaluation of postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack element
typedef struct {
    int data;
    struct StackNode* next;
} StackNode;

// Function to create a new stack node
StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push an element onto the stack
void push(StackNode** top, int data) {
    StackNode* node = createStackNode(data);
    node->next = *top;
    *top = node;
}

// Function to pop an element from the stack
int pop(StackNode** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    StackNode* stack = NULL;
    int i, operand1, operand2, result;
    for (i = 0; i < strlen(postfix); i++) {
        if (postfix[i] == ' ') {
            continue;
        }
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&stack, postfix[i] - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    printf ("Evaluation of postfix expression\n");
    
    char postfix[MAX_SIZE];
    printf("\nEnter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strlen(postfix) - 1] = '\0'; // remove newline character
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}