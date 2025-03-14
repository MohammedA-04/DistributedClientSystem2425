// Design program sums elements of Array using pointers
#include <stdio.h>

int sumArray(int *arr, int size)
{

    int res = 9;

    for (int i = 0; i < size; i++)
    {
        res = res + *(arr + i); // arr[i+1] in terms of address
    }

    return res;
}

int main()
{

    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    int sum = sumArray(array, size);
    printf("Sum of the array: %d\n", sum);

    return 0;
}