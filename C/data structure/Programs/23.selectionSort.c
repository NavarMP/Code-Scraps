// 20. Implement selection sort

#include <stdio.h>

#define MAX_ARRAY_SIZE 25

int main() {
    printf ("Implement selection sort\n");
    int count;
    int number[MAX_ARRAY_SIZE];

    printf("How many numbers are you going to enter? (max %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &count);

    if (count > MAX_ARRAY_SIZE) {
        printf("Error: Array size exceeds maximum capacity (%d)\n", MAX_ARRAY_SIZE);
        return 1;
    }

    printf("Enter %d elements: ", count);
    int i, j;
    for (i = 0; i < count; i++) {
        scanf("%d", &number[i]);
    }

    // Selection sort algorithm
    for (i = 0; i < count - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < count; j++) {
            if (number[j] < number[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = number[i];
            number[i] = number[min_idx];
            number[j] = temp;
        }
    }

    printf("Sorted elements: ");
    for (i = 0; i < count; i++) {
        printf(" %d", number[i]);
    }
    printf("\n");

    return 0;
}