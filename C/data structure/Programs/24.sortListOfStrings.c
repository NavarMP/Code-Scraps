//23. Sort a given list of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two strings
void swap(char** str1, char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Function to sort a list of strings using bubble sort
void sortStrings(char** strings, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                swap(&strings[j], &strings[j + 1]);
            }
        }
    }
}

int main() {
    printf ("Sort a given list of strings\n");
    
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char** strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    printf("Original list of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    sortStrings(strings, n);

    printf("Sorted list of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}