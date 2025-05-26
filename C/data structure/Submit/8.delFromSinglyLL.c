//Delete a given node from a singly linked list

#include <stdio.h>  // Required for standard input/output functions like printf, scanf
#include <stdlib.h> // Required for dynamic memory allocation functions like malloc, free

// Define a structure for the node
struct Node {
    int data;         // Data part of the node
    struct Node *next; // Pointer to the next node in the list
};

// Function to create a linked list with 'n' nodes
struct Node *createLinkedList(int n) {
    struct Node *head = NULL; // Initialize head to NULL for an empty list
    struct Node *temp = NULL; // Temporary pointer to traverse and link nodes
    struct Node *newNode;     // Pointer for the newly created node
    int data, i;

    for (i = 1; i <= n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) { // Check if memory allocation failed
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;   // Assign data to the new node
        newNode->next = NULL;   // New node initially points to NULL

        if (head == NULL) { // If the list is empty, new node becomes the head
            head = newNode;
        } else { // If list is not empty, link the new node to the end of the list
            temp->next = newNode;
        }
        temp = newNode; // Move temp to the newly added node (which is now the last node)
    }
    return head; // Return the head of the created linked list
}

// Function to delete a node at a given position
struct Node *deleteNode(struct Node *head, int position) {
    struct Node *temp = head; // Pointer to traverse to the node to be deleted
    struct Node *prev = NULL; // Pointer to keep track of the previous node
    int i;

    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    // Input validation: Position should be positive
    if (position <= 0) {
        printf("Invalid position. Position must be a positive integer.\n");
        return head;
    }

    // Case 2: Deleting the head node (position = 1)
    if (position == 1) {
        head = temp->next; // Move head to the next node
        printf("Deleted node with data: %d\n", temp->data); // Inform about deleted node
        free(temp);         // Free the memory of the old head
        return head;        // Return the new head
    }

    // Case 3: Deleting a node at a given position (not the head)
    // Traverse to the node just before the one to be deleted
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;      // Keep track of the previous node
        temp = temp->next; // Move to the next node
    }

    // If the position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position out of range. Node not found.\n");
        return head;
    }

    // Unlink the node to be deleted and free its memory
    prev->next = temp->next; // Link previous node to the next node of the deleted one
    printf("Deleted node with data: %d\n", temp->data); // Inform about deleted node
    free(temp);                                        // Free the memory of the deleted node
    return head;                                       // Return the head of the updated list
}

// Function to display the linked list
void displayLinkedList(struct Node *head) {
    struct Node *temp = head; // Temporary pointer to traverse the list

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
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

int main() {
    int n, position;
    struct Node *head = NULL; // Initialize head of the list to NULL

    // Input number of nodes
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return 1; // Exit with an error code
    }

    // Create linked list
    head = createLinkedList(n);

    // Display the linked list
    displayLinkedList(head);

    // Input the position of the node to delete
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    // Delete the node at the given position
    head = deleteNode(head, position);

    // Display the updated linked list
    displayLinkedList(head);

    // Free all allocated memory before program exits
    freeLinkedList(head);

    return 0; // Indicate successful program execution
}