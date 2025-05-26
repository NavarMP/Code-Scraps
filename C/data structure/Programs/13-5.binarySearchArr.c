//12. 5.Search an element in the array using binary search

#include <stdio.h>

int main() {
    printf ("Search an element in the array using binary search\n");
    int n, search, array[100];

    // Get the number of elements from the user
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    // Get the elements from the user
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Get the value to search for from the user
    printf("Enter the value to find: ");
    scanf("%d", &search);

    // Initialize the search boundaries
    int first = 0;
    int last = n - 1;

    // Perform the binary search
    while (first <= last) {
        int middle = (first + last) / 2;

        if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        } else if (array[middle] < search) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }

    // If the element is not found, print a message
    if (first > last) {
        printf("Not found! %d isn't present in the list.\n", search);
    }

    return 0;
}