//8. Delete a given node from a singly linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to delete a node with a given key from the linked list
void deleteNode(Node** head, int key) {
    // Check if the head is NULL
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Check if the node to be deleted is the head node
    if ((*head)->data == key) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to be deleted
    Node* current = *head;
    while (current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }

    // If the node is not found, print an error message
    printf("Node with key %d not found in the list\n", key);
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
    printf("Delete a given node from a singly linked list\n");

    Node* head = NULL;
    int n;

    // Ask the user for the number of nodes in the list
    printf("\nEnter the number of nodes in the list: ");
    scanf("%d", &n);

    // Create the linked list
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    printf("Original list: ");
    printList(head);

    // Ask the user for the node to be deleted
    int key;
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);

    // Delete the node
    deleteNode(&head, key);

    printf("List after deletion: ");
    printList(head);

    return 0;
}