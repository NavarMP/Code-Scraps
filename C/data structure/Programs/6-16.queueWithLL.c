//4. 16.Queue using Linked List

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue queue;

// Function prototypes
void enQueue(int value);
void deQueue();
void display();
int getMenuChoice();
void printMenu();

// Function to add an element to the queue
void enQueue(int value) {
    if ((queue.rear + 1) % QUEUE_SIZE == queue.front) {
        printf("Queue is full. Cannot add element %d.\n", value);
        return;
    }
    if (queue.front == -1) {
        queue.front = 0;
    }
    queue.rear = (queue.rear + 1) % QUEUE_SIZE;
    queue.data[queue.rear] = value;
}

// Function to remove an element from the queue
void deQueue() {
    if (queue.front == -1) {
        printf("Queue is empty. Cannot remove element.\n");
        return;
    }
    printf("Removed element: %d\n", queue.data[queue.front]);
    if (queue.front == queue.rear) {
        queue.front = queue.rear = -1;
    } else {
        queue.front = (queue.front + 1) % QUEUE_SIZE;
    }
}

// Function to display the queue
void display() {
    if (queue.front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue.front;
    while (i != queue.rear) {
        printf("%d ", queue.data[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("%d\n", queue.data[queue.rear]);
}

// Function to get menu choice from user
int getMenuChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to print the menu
void printMenu() {
    printf("Queue Operations\n");
    printf("---------------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");
}

int main() {
    printf ("Create queue using array\n\n");
    
    queue.front = queue.rear = -1;
    int choice;
    while (1) {
        printMenu();
        choice = getMenuChoice();
        switch (choice) {
            case 1: {
                int value;
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enQueue(value);
                printf ("Enqueue successfull!\n\n");
                break;
            }
            case 2:
                deQueue();
                printf ("Dequeue successfull!\n\n");
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}