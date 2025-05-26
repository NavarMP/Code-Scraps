// 1. Append two arrays

#include <stdio.h>

int main() {
    int aSize, bSize, mSize, i, j;
    int a[10], b[10], Merged[20]; // Fixed array sizes for demonstration

    printf("\n Please Enter the First Array Size: ");
    scanf("%d", &aSize);

    printf("\n Please Enter the First Array Elements: ");
    for (i = 0; i < aSize; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n Please Enter the Second Array Size: ");
    scanf("%d", &bSize);

    printf("\n Please Enter the Second Array Elements: ");
    for (i = 0; i < bSize; i++) {
        scanf("%d", &b[i]);
    }

    // Copy elements of the first array to the merged array
    for (i = 0; i < aSize; i++) {
        Merged[i] = a[i];
    }

    // Copy elements of the second array to the merged array
    mSize = aSize + bSize;
    for (i = 0, j = aSize; j < mSize && i < bSize; i++, j++) {
        Merged[j] = b[i];
    }

    printf("\n Merged Array Elements:\n");
    for (i = 0; i < mSize; i++) {
        printf(" %d\t", Merged[i]);
    }
    printf("\n"); // Add a newline at the end for better formatting

    return 0;
}