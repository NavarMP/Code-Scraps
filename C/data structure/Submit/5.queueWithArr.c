//Queue using Array

#include <stdio.h>
#include <stdlib.h> // Required for exit()

#define SIZE 10 // Define the maximum size of the queue

// Function prototypes
void enQueue(int);
void deQueue();
void display();

// Global variables for the queue
int queue[SIZE], front = -1, rear = -1;

int main() {
    int value, choice;

    // clrscr() is a conio.h function and is specific to some compilers (like Turbo C++).
    // It's not standard C. For cross-platform compatibility, it's often removed.
    // clrscr();

    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); // Exit the program
            default:
                printf("\nWrong selection! Please try again!\n"); // Added newline for cleaner output
        }
    }
    return 0; // Will not be reached due to exit(0)
}

// Function to insert an element into the queue
void enQueue(int value) {
    if (rear == SIZE - 1) {
        printf("\nQueue is Full! Insertion is not possible!\n"); // Added newline
    } else {
        if (front == -1) { // If the queue was initially empty
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\nInsertion successful!\n"); // Added newline
    }
}

// Function to delete an element from the queue
void deQueue() {
    if (front == -1 || front > rear) { // Corrected condition for empty queue
        printf("\nQueue is Empty! Deletion is not possible!\n"); // Added newline
    } else {
        printf("\nDeleted: %d\n", queue[front]); // Added newline
        front++;
        if (front > rear) { // If queue becomes empty after deletion
            front = -1;
            rear = -1;
        }
    }
}

// Function to display elements of the queue
void display() {
    if (front == -1 || front > rear) { // Corrected condition for empty queue
        printf("\nQueue is Empty!\n"); // Added newline
    } else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n"); // Added newline for cleaner output
    }
}