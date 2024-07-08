#include <stdio.h>
#include <mymath.h>
#include <d1/mymod.h>

int main()
{
    double x, y;
    int a, b;
    printf("Enter first number : ");
    scanf("%lf", &x);
    printf("Enter second number : ");
    scanf("%lf", &y);

    printf("Enter third number : ");
    scanf("%d", &a);
    printf("Enter fourth number : ");
    scanf("%d", &b);

    printf("x + y = %.2lf \n", myadd(x, y));
    printf("x - y = %.2lf \n", mysub(x, y));
    printf("x * y = %.2lf \n", mymul(x, y));
    printf("x / y = %.2lf \n", mydiv(x, y));
    printf("a %% b = %d \n", mymod(a, b)); // Note the use of %% to print the percent symbol

    return 0;
}
