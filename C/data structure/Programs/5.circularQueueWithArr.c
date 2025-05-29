//5. Circular queue using array

#include <stdio.h>

#define SIZE 5

int cQueue[SIZE];
int front = -1, rear = -1;

void enQueue(int value);
void deQueue();
void display();

int main() {
    printf ("Circular queue using array\n");

    int choice, value;

    printf ("\nQueue is now empty\n");
    while (1) {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
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
                return 0; // exit(0) is not necessary, return 0 is enough
            default:
                printf("\nPlease select the correct choice!!!\n");
        }
    }
    return 0; // added return 0 at the end of main
}

void enQueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("\nCircular Queue is Full! Insertion not possible!!!\n");
    } else {
        if (rear == SIZE - 1 && front != 0) {
            rear = -1;
        }
        cQueue[++rear] = value;
        printf("\nInsertion Success!!!\n");
        if (front == -1) {
            front = 0;
        }
    }
}

void deQueue() {
    if (front == -1 && rear == -1) {
        printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
    } else {
        printf("\nDeleted element : %d\n", cQueue[front++]);
        if (front == SIZE) {
            front = 0;
        }
        if (front - 1 == rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nCircular Queue is Empty!!!\n");
    } else {
        int i = front;
        printf("\nCircular Queue Elements are : \n");
        if (front <= rear) {
            while (i <= rear) {
                printf("%d\t", cQueue[i++]);
            }
        } else {
            while (i <= SIZE - 1) {
                printf("%d\t", cQueue[i++]);
            }
            i = 0;
            while (i <= rear) {
                printf("%d\t", cQueue[i++]);
            }
        }
    }
}