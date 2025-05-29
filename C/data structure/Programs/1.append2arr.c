//1. Append 2 arrays

#include <stdio.h>

//read array elements
void readArr (int arr[], int size) {
    printf ("Please enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf ("%d", &arr[i]);
    }
}

//print array elements
void printArr (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf ("%d\t", arr[i]);
    }
    printf ("\n");
}

//merge 2 arrays
void mergeArr (int a[], int b[], int merged[], int aSize, int bSize) {
    //copy from 1st array to merged array
    for (int i = 0; i < aSize; i++) {
        merged[i] = a[i];
    }

    //copy from 2nd to merged array
    for (int i = 0, j = aSize; j < aSize + bSize; i++, j++) {
        merged[j] = b[i];
    }
}
int main () {
    printf ("Append two arrays\n");
    const int maxSize = 10;
    int a[maxSize], b[maxSize], merged[maxSize * 2];
    int aSize, bSize;

    //read size of 1st array
    printf ("Please enter the size of the first array (max %d): ", maxSize);
    scanf ("%d", &aSize);

    //Check validity of size
    if (aSize < 1 || aSize > maxSize) {
        printf ("Invalid size. Exiting...\n");
        return 1;
    }

    //read elements of the 1st array
    readArr (a, aSize);

    //read the size of the 2nd array
    printf ("Please enter the size of the second array (max %d): ", maxSize);
    scanf ("%d", &bSize);

     // Check if the size is valid
    if (bSize < 1 || bSize > maxSize) {
        printf("Invalid size. Exiting...\n");
        return 1;
    }

    // Read the elements of the second array
    readArr(b, bSize);

    // Merge the two arrays
    mergeArr(a, b, merged, aSize, bSize);

    // Print the merged array
    printf("Merged array elements:\n");
    printArr(merged, aSize + bSize);

    return 0;
}