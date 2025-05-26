//Queue using Linked List

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue *q, int data) {
    struct Node *temp = newNode(data);

    // If the queue is empty, the new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of the queue and update rear
    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued: %d\n", data); // Added print for clarity
}

// Function to remove an element from the queue (dequeue)
void dequeue(struct Queue *q) {
    // If the queue is empty, return
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    // Store the previous front and move the front pointer to the next node
    struct Node *temp = q->front;
    q->front = q->front->next;

    // If the front becomes NULL, then change rear to NULL (queue is now empty)
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("Dequeued: %d\n", temp->data); // Print the dequeued element
    free(temp); // Free the memory of the dequeued node
}

// Function to display the queue
void displayQueue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue after enqueue operations: ");
    displayQueue(q);

    dequeue(q);
    printf("Queue after dequeue operation: ");
    displayQueue(q);

    dequeue(q);
    printf("Queue after second dequeue operation: ");
    displayQueue(q);

    dequeue(q); // Dequeue last element
    printf("Queue after third dequeue operation: ");
    displayQueue(q);

    dequeue(q); // Try to dequeue from an empty queue

    // Free the queue structure itself after all operations
    free(q);
    q = NULL; // Set to NULL to prevent dangling pointer issues

    return 0;
}