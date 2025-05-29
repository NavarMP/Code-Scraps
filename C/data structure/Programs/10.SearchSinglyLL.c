//10. Create a singly linked list and search an element

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an element in the linked list
int searchElement(Node* head, int key) {
    Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    return found;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf ("Create a singly linked list and search an element\n");
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

    printf("Linked List: ");
    printList(head);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int found = searchElement(head, key);
    if (found) {
        printf("Element %d found in the linked list.\n", key);
    } else {
        printf("Element %d not found in the linked list.\n", key);
    }

    return 0;
}