// Write program calculates length of string using pointers
#include <stdio.h>

int strLength(char *str)
{

    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++; // move to next character in string
    }
}

int main()
{

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Length of the string: %d\n", strLength(input));
    return 0;
}