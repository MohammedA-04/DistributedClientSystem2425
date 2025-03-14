// Function Pointers to perform arthmetic operations +,/,-,*
#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Division by zero is not allowed\n");
        return 0;
    }
}

int sub(int a, int b)
{
    return a - b;
}

int main()
{

    int n1, n2;
    int (*operation)(int, int);

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    // choose operation
    int choice;
    printf("Choose operation: \n1. Addition\n2. Multiplication\n3. Division\n4. Subtraction\n");
    scanf("%d", &choice);

    // Assign function pointer
    switch (choice)
    {
    case 1:
        operation = add;
        break;
    case 2:
        operation = mul;
        break;
    case 3:
        operation = div;
        break;
    case 4:
        operation = sub;
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    // performed selected ops and output
    printf("Result: %d\n", operation(n1, n2));

    return 0;
}
