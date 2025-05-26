//Search an element in a singly linked list

#include <stdio.h>  // Required for standard input/output functions like printf, scanf
#include <stdlib.h> // Required for dynamic memory allocation functions like malloc, free

// Define the structure for a node in the linked list
struct Node {
    int data;          // Data held by the node
    struct Node *next; // Pointer to the next node in the list
};

// Function to insert a new node at the end of the linked list
// head is a double pointer because the head of the list might change (if list was empty)
void insertNode(struct Node **head, int data) {
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check for successful memory allocation
        perror("Memory allocation failed");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }

    struct Node *last = *head; // Temporary pointer to traverse to the last node
    newNode->data = data;     // Assign the given data to the new node
    newNode->next = NULL;     // New node will be the last, so its next is NULL

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }
    // Link the new node to the end of the list
    last->next = newNode;
}

// Function to search for an element in the linked list
// Returns 1 if element is found, 0 otherwise
int searchElement(struct Node *head, int value) {
    struct Node *current = head; // Start traversal from the head

    // Iterate through the list until the end is reached
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Element found
        }
        current = current->next; // Move to the next node
    }
    return 0; // Element not found after traversing the entire list
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head; // Temporary pointer to traverse the list
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;           // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to free all nodes in the linked list (to prevent memory leaks)
void freeLinkedList(struct Node *head) {
    struct Node *current = head;
    struct Node *next_node;
    while (current != NULL) {
        next_node = current->next; // Store the next node before freeing the current one
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
}

// Main function
int main() {
    struct Node *head = NULL; // Initialize head of the linked list to NULL
    int n, value, searchVal, i;

    // Accept the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input validation for number of nodes
    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return 1; // Exit with an error code
    }

    // Accept the values from the user and insert them into the linked list
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertNode(&head, value); // Pass address of head to modify it
    }

    // Display the list
    printf("Linked list:\n");
    printList(head);

    // Accept the value to search
    printf("Enter value to search in the list: ");
    scanf("%d", &searchVal);

    // Search the element in the list and print the result
    if (searchElement(head, searchVal)) {
        printf("Element %d found in the list.\n", searchVal);
    } else {
        printf("Element %d not found in the list.\n", searchVal);
    }

    // Free all allocated memory before program exits
    freeLinkedList(head);
    head = NULL; // Set head to NULL after freeing

    return 0; // Indicate successful program execution
}