// 21. Implement insertion sort

#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int main() {
    printf ("Implement insertion sort\n");
    
    int n;
    int array[MAX_ARRAY_SIZE];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX_ARRAY_SIZE) {
        printf("Error: Array size exceeds maximum capacity (%d)\n", MAX_ARRAY_SIZE);
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionSort(array, n);

    printf("Sorted list in ascending order:\n");
    printArray(array, n);

    return 0;
}