//7. Create and display a singly linked list of n nodes

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
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
}

// Function to display the linked list
void displayList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf ("Create and display a singly linked list of n nodes\n");

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("Linked list: ");
    displayList(head);
    return 0;
}