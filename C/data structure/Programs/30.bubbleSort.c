//30.bubble sort array

#include <stdio.h>

// Define a maximum size for the array.
// Using a named constant improves readability and maintainability.
#define MAX_ARRAY_SIZE 10

/**
 * @brief Sorts an integer array using an optimized Bubble Sort algorithm.
 *
 * This function iterates through the array, comparing adjacent elements and
 * swapping them if they are in the wrong order. The largest unsorted elements
 * "bubble" to their correct sorted position at the end of the array with each pass.
 * An optimization is included: if a pass completes with no swaps, the array
 * is already sorted, and the function terminates early.
 *
 * @param arr The integer array to be sorted. This array is modified in place.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; // Flag to detect if any swaps occurred in a pass

    if (n <= 0) { // No need to sort an empty or invalidly sized array
        return;
    }

    // Outer loop for each pass through the array
    // In the worst case, n-1 passes are needed.
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Initialize swapped to false at the start of each pass

        // Inner loop to compare adjacent elements
        // The range of j decreases with each pass i, as the last i elements are already sorted.
        for (j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // A swap occurred in this pass
            }
        }

        // Optimization: If no two elements were swapped in the inner loop,
        // the array is already sorted, so we can break out of the outer loop.
        if (swapped == 0) {
            break;
        }
    }
}

/**
 * @brief Displays the elements of an integer array.
 *
 * @param arr The constant integer array to be displayed. The array is not modified.
 * @param n The number of elements in the array.
 */
void displayArray(const int arr[], int n) {
    if (n <= 0) {
        printf("(Array is empty or has invalid size to display)\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int num_elements, i; // Using num_elements for clarity

    // Input the number of elements from the user
    printf("Enter number of elements (1 to %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &num_elements);

    // Validate the input size
    if (num_elements < 1 || num_elements > MAX_ARRAY_SIZE) {
        fprintf(stderr, "Error: Number of elements must be between 1 and %d.\n", MAX_ARRAY_SIZE);
        return 1; // Exit with an error code
    }

    // Input elements into the array
    printf("Enter %d integer elements:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("\nOriginal Array: ");
    displayArray(arr, num_elements);

    // Perform bubble sort
    bubbleSort(arr, num_elements);

    // Display the sorted array
    printf("Sorted Array  : ");
    displayArray(arr, num_elements);

    return 0; // Indicate successful execution
}