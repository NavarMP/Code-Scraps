// Circular Linked List

#include <stdio.h>  // For printf function
#include <stdlib.h> // For malloc and free functions

// Node structure for circular linked list
struct Node {
    int data;              // Stores the integer value
    struct Node* next;     // Pointer to the next node
};

struct Node* head = NULL;  // Global pointer to the first node

// Function to insert a new node at the end of circular list
void insertEnd(int value) {
    // Allocate memory for new node
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {  // Check if memory allocation failed
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = value;  // Set the data value
    
    if (head == NULL) {  // If list is empty
        head = newNode;
        newNode->next = head; // Point to itself (circular)
    } else {  // If list has nodes
        struct Node* temp = head;
        // Traverse to the last node (one before head)
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;    // Link last node to new node
        newNode->next = head;    // Link new node back to head
    }
}

// Function to display all nodes in the circular linked list
void display() {
    if (head == NULL) {  // Check if list is empty
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;  // Start from head node
    printf("Circular Linked List: ");
    do {  // Use do-while to ensure at least one iteration
        printf("%d ", temp->data);  // Print current node's data
        temp = temp->next;          // Move to next node
    } while (temp != head);  // Stop when we reach back to head
    printf("\n");
}

// Function to free all allocated memory and prevent memory leaks
void freeList() {
    if (head == NULL) return;  // Nothing to free if list is empty
    
    struct Node* current = head;  // Start from head
    struct Node* next;            // Temporary pointer for next node
    
    do {  // Traverse the circular list
        next = current->next;     // Store next node before freeing current
        free(current);            // Free current node's memory
        current = next;           // Move to next node
    } while (current != head);    // Stop when we complete the circle
    
    head = NULL;  // Reset head pointer to indicate empty list
}

// Main function - program entry point
int main() {
    // Insert test values into the circular linked list
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    
    // Display the complete list
    display();
    
    // Clean up allocated memory before program ends
    freeList();
    return 0;  // Indicate successful program termination
}