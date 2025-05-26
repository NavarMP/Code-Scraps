/* 10.  11.Create a doubly linked list of integers and
display in forward and backward direction */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to display the list in forward direction
void displayForward(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to display the list in backward direction
void displayBackward(Node* head) {
    if (head == NULL) return;
    Node* lastNode = head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    while (lastNode) {
        printf("%d ", lastNode->data);
        lastNode = lastNode->prev;
    }
    printf("\n");
}

int main() {
    printf ("Create a doubly linked list of integers and display in forward and backward direction\n");
    
    Node* head = NULL;
    int numNodes;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("Enter node %d data: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Forward direction: ");
    displayForward(head);

    printf("Backward direction: ");
    displayBackward(head);

    return 0;
}