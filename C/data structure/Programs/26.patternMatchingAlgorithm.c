// 26. Implement Pattern matching algorithm

#include <stdio.h>
#include <string.h>

// Function to perform pattern matching
int match(char text[], char pattern[]) {
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    // If pattern is longer than text, it can't be found
    if (pattern_length > text_length) {
        return -1;
    }

    // Iterate over the text
    for (int i = 0; i <= text_length - pattern_length; i++) {
        int j = 0; // Index for the pattern
        int k = i; // Index for the text

        // Check if the pattern matches at the current position
        while (j < pattern_length && pattern[j] == text[k]) {
            j++;
            k++;
        }

        // If the entire pattern was matched, return the position
        if (j == pattern_length) {
            return i;
        }
    }

    // If no match was found, return -1
    return -1;
}

int main() {
    printf ("Implement Pattern matching algorithm");
    
    char text[100];
    char pattern[100];
    int position;

    printf("Enter some text:\n");
    fgets(text, sizeof(text), stdin);

    printf("Enter a string to find:\n");
    fgets(pattern, sizeof(pattern), stdin);

    // Remove the newline character from the input strings
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;

    position = match(text, pattern);

    if (position != -1) {
        printf("Found at location: %d\n", position + 1);
    } else {
        printf("Not found.\n");
    }

    return 0;
}