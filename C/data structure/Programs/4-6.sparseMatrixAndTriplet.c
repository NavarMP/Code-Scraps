//13. 6.Read a sparse matrix and display its triplet representation using array

#include <stdio.h>

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} Triplet;

// Function to read a sparse matrix
void readSparseMatrix(int rows, int cols, Triplet triplets[]) {
    int i, j, count = 0;
    printf("Enter the sparse matrix elements (row, col, value):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int value;
            printf("Element (%d, %d): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                triplets[count].row = i;
                triplets[count].col = j;
                triplets[count].value = value;
                count++;
            }
        }
    }
}

// Function to display the triplet representation
void displayTripletRepresentation(Triplet triplets[], int count) {
    printf("Triplet representation:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", triplets[i].row, triplets[i].col, triplets[i].value);
    }
}

int main() {
    printf ("Read a sparse matrix and display its triplet representation using array\n");
    int rows, cols;
    printf("\nEnter the number of rows: ");
    scanf("%d", &rows);
    printf("\nEnter the number of columns: ");
    scanf("%d", &cols);

    Triplet triplets[rows * cols]; // maximum possible number of non-zero elements
    readSparseMatrix(rows, cols, triplets);

    int count = 0;
    for (int i = 0; i < rows * cols; i++) {
        if (triplets[i].value != 0) {
            count++;
        }
    }

    displayTripletRepresentation(triplets, count);

    return 0;
}