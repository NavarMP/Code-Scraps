//Singly Linked List of n nodes

#include <stdio.h>   // Required for standard input/output functions like printf
#include <stdlib.h>  // Required for dynamic memory allocation functions like malloc

// Define the structure of a node in the linked list
struct Node {
    int data;          // Data held by the node
    struct Node *next; // Pointer to the next node in the list
};

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *current = head; // Start from the head of the list

    // Traverse the list until the end (NULL) is reached
    while (current != NULL) {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;         // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to create a new node
struct Node *createNode(int data) {
    // Dynamically allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        perror("Memory allocation failed"); // Print an error message
        exit(EXIT_FAILURE);                 // Exit the program if allocation fails
    }

    newNode->data = data;   // Assign the given data to the new node
    newNode->next = NULL;   // Initialize the next pointer to NULL
    return newNode;         // Return the newly created node
}

int main() {
    // Create individual nodes with specific data
    struct Node *head = createNode(1);
    struct Node *second = createNode(2);
    struct Node *third = createNode(3);
    struct Node *fourth = createNode(4);

    // Link the nodes together to form the linked list
    head->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next remains NULL, marking the end of the list

    // Traverse and print the entire linked list
    printf("Linked List: ");
    printList(head);

    // Remember to free the allocated memory to prevent memory leaks
    // This is crucial in C to manage dynamic memory.
    struct Node *current = head;
    struct Node *next_node;
    while (current != NULL) {
        next_node = current->next; // Store the next node before freeing the current one
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
    head = NULL; // Set head to NULL after freeing all nodes

    return 0; // Indicate successful program execution
}