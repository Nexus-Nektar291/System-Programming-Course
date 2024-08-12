#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int sub(int, int);
int mul(int, int);

int main(int argc, char const *argv[])
{
    int (*fptr_arr[3])(int, int) = {&add, &sub, &mul};
    int ch, a, b;

    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);
    puts("");

    printf("Enter your choice (0 for Addition, 1 for Subtraction, 2 for Multiplication): ");
    scanf("%d", &ch);

    int rv;
    if (ch == 0)
    {
        rv = fptr_arr[0](a, b);
        printf("Addition of %d and %d is: %d\n", a, b, rv);
    }
    else if (ch == 1)
    {
        rv = fptr_arr[1](a, b);
        printf("Subtraction of %d and %d is: %d\n", a, b, rv);
    }
    else if (ch == 2)
    {
        rv = fptr_arr[2](a, b);
        printf("Multiplication of %d and %d is: %d\n", a, b, rv);
    }

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}