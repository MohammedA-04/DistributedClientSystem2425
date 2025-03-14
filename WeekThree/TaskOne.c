// Write C code takes two ints as input, sawp their values using pointers and print the swapped values.

#include <stdio.h>

void swapFunction(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("Number 1 after swapping: %d\n", *a);
    printf("Number 2 after swapping: %d\n", *b);
}

int main()
{

    int a, b;

    // user intput
    printf("Enter the first number: ");
    scanf("%d", &a); // & pass variable address
    printf("Enter the second number: ");
    scanf("%d", &b);

    // swap them
    swapFunction(&a, &b);

    return 0;
}