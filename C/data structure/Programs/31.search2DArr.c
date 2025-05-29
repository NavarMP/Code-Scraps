#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

/**
 * @brief Searches for a target element in a dynamically allocated 2D array.
 *
 * This function iterates through all elements of the given 2D array
 * to find the specified target value. If the element is found, its position
 * (row and column indices) is printed, and the function returns 1.
 * If the element is not found after checking all positions, a "not found"
 * message is printed, and the function returns 0.
 *
 * @param rows The number of rows in the 2D array.
 * @param cols The number of columns in the 2D array.
 * @param arr A pointer to a pointer to integers, representing the 2D array.
 * It's expected to be dynamically allocated.
 * @param target The integer value to search for within the array.
 * @return 1 if the element is found, 0 otherwise.
 */
int searchElement(int rows, int cols, int **arr, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                printf("Element %d found at position (%d, %d)\n", target, i, j);
                return 1; // Element found
            }
        }
    }
    printf("Element %d not found\n", target);
    return 0; // Element not found
}

/**
 * @brief Main function to demonstrate 2D array search.
 *
 * Prompts the user to enter the dimensions (rows and columns) of a 2D array,
 * then to input its elements. Afterwards, it asks for a target element to search
 * and calls the searchElement function to find it. Handles dynamic memory
 * allocation and deallocation for the 2D array.
 *
 * @return 0 if the program executes successfully, 1 if memory allocation fails.
 */
int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the 2D array
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate an error
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1; // Indicate an error
        }
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Call the search function
    searchElement(rows, cols, arr, target);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}