//Sort singly linked list

#include <stdio.h>  // Required for standard input/output functions like printf, scanf
#include <stdlib.h> // Required for dynamic memory allocation functions like malloc, free

// Define the structure for a node
struct Node {
    int data;          // Data held by the node
    struct Node *next; // Pointer to the next node in the list
};

// Function to insert a new node at the end of the linked list
void insertNode(struct Node **head, int data) {
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check if memory allocation failed
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    struct Node *last = *head; // Pointer to traverse to the last node
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

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;           // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to sort the linked list using bubble sort
void sortList(struct Node *head) {
    int swapped;         // Flag to check if any swaps occurred in an iteration
    int tempData;        // Temporary variable for swapping data
    struct Node *ptr1;   // Pointer for the current node in the outer loop
    struct Node *lptr = NULL; // Pointer to the last sorted element (optimization)

    // If the list is empty, there's nothing to sort
    if (head == NULL)
        return;

    // Outer loop for bubble sort, continues as long as swaps occur
    do {
        swapped = 0; // Reset swapped flag for each pass
        ptr1 = head; // Start from the head for each pass

        // Inner loop: traverse the list up to the last sorted element
        while (ptr1->next != lptr) {
            // Compare adjacent nodes and swap if they are in the wrong order
            if (ptr1->data > ptr1->next->data) {
                // Swap the data values (only data is swapped, not the nodes themselves)
                tempData = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempData;
                swapped = 1; // Set swapped flag to true
            }
            ptr1 = ptr1->next; // Move to the next node
        }
        lptr = ptr1; // After a pass, the last element is in its correct place
    } while (swapped); // Continue if any swaps were made in the current pass
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
    int n, value, i;

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

    // Display the list before sorting
    printf("Linked list before sorting:\n");
    printList(head);

    // Sort the linked list
    sortList(head);

    // Display the list after sorting
    printf("Linked list after sorting:\n");
    printList(head);

    // Free all allocated memory before program exits
    freeLinkedList(head);
    head = NULL; // Set head to NULL after freeing

    return 0; // Indicate successful program execution
}