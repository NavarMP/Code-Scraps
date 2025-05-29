// 22. Implement quick sort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Function to implement quick sort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    printf ("Implement quick sort\n");

    int count, number[25];

    printf("How many elements are you going to enter?: ");
    scanf("%d", &count);

    if (count > 25) {
        printf("Error: Maximum 25 elements can be entered.\n");
        return 1;
    }

    printf("Enter %d elements: ", count);
    for (int i = 0; i < count; i++)
        scanf("%d", &number[i]);

    quicksort(number, 0, count - 1);

    printf("Order of Sorted elements: ");
    for (int i = 0; i < count; i++)
        printf(" %d", number[i]);

    return 0;
}