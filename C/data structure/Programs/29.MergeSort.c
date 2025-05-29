// Merge sort Array

#include <stdio.h>

// Define a maximum capacity for the arrays.
// This helps in managing array sizes and can be easily changed if needed.
// For applications requiring variable array sizes at runtime,
// dynamic memory allocation (e.g., using malloc) would be a more robust approach.
#define MAX_CAPACITY 100

/*
 * Merges two sorted arrays, A and B, into a single sorted array, 'merged'.
 *
 * Parameters:
 * A[]      : The first sorted integer array.
 * n        : The number of elements in array A.
 * B[]      : The second sorted integer array.
 * m        : The number of elements in array B.
 * merged[] : The output array where the merged result will be stored.
 * Its capacity should be at least n + m.
 */
void mergeSortedArrays(int A[], int n, int B[], int m, int merged[]) {
    int i = 0; // Pointer/index for the current element in array A
    int j = 0; // Pointer/index for the current element in array B
    int k = 0; // Pointer/index for the current position in the merged array

    // Traverse both arrays A and B
    // Compare elements from A and B and place the smaller one into the merged array
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            merged[k++] = A[i++]; // Copy element from A and increment pointers
        } else {
            merged[k++] = B[j++]; // Copy element from B and increment pointers
        }
    }

    // After the main loop, one of the arrays might still have remaining elements.
    // Copy any remaining elements from array A
    while (i < n) {
        merged[k++] = A[i++];
    }

    // Copy any remaining elements from array B
    while (j < m) {
        merged[k++] = B[j++];
    }
}

int main() {
    // Declare arrays using the defined maximum capacity.
    // The mergedResult array needs to be large enough to hold all elements from both arrA and arrB.
    int arrA[MAX_CAPACITY], arrB[MAX_CAPACITY], mergedResult[2 * MAX_CAPACITY];
    int sizeA, sizeB; // Variables to store the actual number of elements entered by the user
    int idx;          // Loop iterator variable

    // Get input for the first sorted array
    printf("Enter the number of elements in first sorted array (up to %d): ", MAX_CAPACITY);
    scanf("%d", &sizeA);

    // It's good practice to validate input, e.g., check if sizeA is within [0, MAX_CAPACITY].
    // For brevity, as per the request, extensive validation is omitted here.

    printf("Enter %d sorted elements for the first array: ", sizeA);
    for (idx = 0; idx < sizeA; idx++) {
        scanf("%d", &arrA[idx]);
    }

    // Get input for the second sorted array
    printf("Enter the number of elements in second sorted array (up to %d): ", MAX_CAPACITY);
    scanf("%d", &sizeB);

    // Similar validation for sizeB could be added here.

    printf("Enter %d sorted elements for the second array: ", sizeB);
    for (idx = 0; idx < sizeB; idx++) {
        scanf("%d", &arrB[idx]);
    }

    // Call the function to merge the two sorted arrays
    mergeSortedArrays(arrA, sizeA, arrB, sizeB, mergedResult);

    // Print the final merged and sorted array
    printf("Merged Sorted Array: ");
    for (idx = 0; idx < sizeA + sizeB; idx++) {
        printf("%d ", mergedResult[idx]);
    }
    printf("\n"); // Add a newline for cleaner terminal output

    return 0; // Indicate successful program execution
}
