// 24. Reverse a string using pointers

#include <stdio.h>
#include <string.h>

int string_length(const char*); // added const keyword
void reverse(char*); // function prototype

int main()
{
    printf ("Reverse a string using pointers\n");
    
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin); // replaced gets with fgets for safety
    reverse(s);
    printf("Reverse of the string is \"%s\".\n", s);
    return 0;
}

void reverse(char *s)
{
    int length = string_length(s);
    char *begin = s;
    char *end = s + length - 1; // calculate end pointer directly

    while (begin < end)
    {
        char temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}

int string_length(const char *pointer)
{
    int c = 0;
    while (*(pointer + c) != '\0')
        c++;
    return c;
}