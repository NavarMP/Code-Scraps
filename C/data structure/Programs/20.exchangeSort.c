// 19. Implement exchange sort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform exchange sort
void exchange_sort(int a[], int elements) {
    int i, j;
    for (i = 0; i < elements - 1; i++) {
        for (j = i + 1; j < elements; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    printf ("Implement exchange sort\n");

    int numbers[] = { 10, 9, 8, 23, 19, 11, 2, 7, 1, 13, 12 };
    int elements = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before the sort the array was:\n");
    for (int i = 0; i < elements; i++) {
        printf(" %d ", numbers[i]);
    }

    exchange_sort(numbers, elements);

    printf("\nAfter the sort the array was:\n");
    for (int i = 0; i < elements; i++) {
        printf(" %d ", numbers[i]);
    }

    return 0;
}