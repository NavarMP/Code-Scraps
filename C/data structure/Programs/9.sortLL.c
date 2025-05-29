// 9. Sort a singly linked list (bubble sort)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to sort the linked list using bubble sort
void sortList(Node** head) {
    int swapped;
    Node* current;
    Node* nextNode;

    if (*head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *head;

        while (current->next != NULL) {
            nextNode = current->next;

            if (current->data > nextNode->data) {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf ("Sort a singly linked list (bubble sort)\n");

    Node* head = NULL;
    int numNodes;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("\nEnter node %d data: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original list: ");
    printList(head);

    // Sort the linked list
    sortList(&head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}