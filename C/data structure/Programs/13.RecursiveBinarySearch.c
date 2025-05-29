//recursive binary search in array

#include <stdio.h>

// Function for Recursive Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    // Base case: element is not found
    if (low > high) {
        return -1;
    }
    
    // Calculate middle index to avoid overflow
    int mid = low + (high - low) / 2;
    
    // Check if the element is at mid
    if (arr[mid] == target) {
        return mid;
    }
    
    // If target is greater, search in the right half
    if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, high, target);
    }
    
    // If target is smaller, search in the left half
    return binarySearch(arr, low, mid - 1, target);
}

int main() {
    int arr[100], size, target;
    
    printf("Recursive Binary Search\n");
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter %d sorted integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }
    
    return 0;
}