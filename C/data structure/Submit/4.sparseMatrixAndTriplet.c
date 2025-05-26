//Sparce matrix and its triplet representation using array

#include <stdio.h>

#define MAX 100 // Maximum number of non-zero elements for the sparse matrix representation

// Define the structure for a sparse matrix element (triplet format)
struct SparseMatrix {
    int row;    // Row index
    int col;    // Column index
    int value;  // Value at (row, col)
};

int main() {
    int matrix[10][10];               // Original matrix (max 10x10)
    struct SparseMatrix sparse[MAX];  // Array to store sparse matrix elements
    int i, j, rows, cols, nonZeroCount = 0;

    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d%d", &rows, &cols);

    // Input validation for matrix dimensions
    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
        printf("Invalid matrix dimensions. Rows and columns should be between 1 and 10.\n");
        return 1; // Indicate an error
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);

            // If the element is non-zero, store it in the sparse matrix array
            if (matrix[i][j] != 0) {
                // Check if we exceed the MAX capacity for sparse representation
                if (nonZeroCount >= MAX) {
                    printf("Warning: Maximum sparse elements (%d) exceeded. Some non-zero elements might not be stored.\n", MAX);
                    break; // Exit inner loop if MAX is reached
                }
                sparse[nonZeroCount].row = i;
                sparse[nonZeroCount].col = j;
                sparse[nonZeroCount].value = matrix[i][j];
                nonZeroCount++;
            }
        }
        if (nonZeroCount >= MAX) { // Exit outer loop if MAX is reached
            break;
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // Newline after each row
    }

    printf("\nSparse Matrix Representation (Triplet Format):\n");
    printf("Row   Column   Value\n");
    for (i = 0; i < nonZeroCount; i++) {
        printf("%d      %d      %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0; // Indicate successful execution
}