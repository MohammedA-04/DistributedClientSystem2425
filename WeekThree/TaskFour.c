// dynamic memory allocation in C for an int, user input prints sqaured value

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *num;

    num = (int *)malloc(sizeof(int));

    // in
    printf("Enter a number: ");
    scanf("%d", num);

    // out
    printf("Squared value: %d\n", (*num) * (*num));

    // free memory we allocated!
    free(num);

    return 0;
}