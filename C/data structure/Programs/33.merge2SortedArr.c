#include <stdio.h>

// Function to merge two sorted arrays A[] and B[] into merged[]
void mergeSortedArrays(int A[], int n, int B[], int m, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge until one of the arrays ends
    while (i < n && j < m) {
        if (A[i] < B[j])
            merged[k++] = A[i++];
        else
            merged[k++] = B[j++];
    }

    // Copy remaining elements from A[]
    while (i < n)
        merged[k++] = A[i++];

    // Copy remaining elements from B[]
    while (j < m)
        merged[k++] = B[j++];
}

int main() {
    int A[100], B[100], merged[200];
    int n, m, i;

    // Input for array A
    printf("Enter the number of elements in first sorted array: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements for the first array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Input for array B
    printf("Enter the number of elements in second sorted array: ");
    scanf("%d", &m);
    printf("Enter %d sorted elements for the second array: ", m);
    for (i = 0; i < m; i++)
        scanf("%d", &B[i]);

    // Merge the arrays
    mergeSortedArrays(A, n, B, m, merged);

    // Output the merged array
    printf("Merged Sorted Array: ");
    for (i = 0; i < n + m; i++)
        printf("%d ", merged[i]);

    printf("\n");
    return 0;
}
