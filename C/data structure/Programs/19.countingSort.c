#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 1) return;
    
    // Find min and max elements
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    // Calculate range and create count array
    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));
    if (!count) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // Calculate cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Create output array
    int* output = (int*)malloc(n * sizeof(int));
    if (!output) {
        printf("Memory allocation failed!\n");
        free(count);
        return;
    }
    
    // Build output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    // Clean up memory
    free(count);
    free(output);
}

void printArray(int arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n;
    
    printf("Counting Sort Algorithm\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printArray(arr, n, "Original Array");
    countingSort(arr, n);
    printArray(arr, n, "Sorted Array");
    
    return 0;
}