#include <stdio.h>
#include <mymath.h>

int main()
{
	double x , y;
	printf("Enter first number : ");
	scanf("%lf",&x);
	printf("Enter second number : ");
	scanf("%lf",&y);

	printf("x + y = %.2lf \n",myadd(x,y));
	printf("x - y = %.2lf \n",mysub(x,y));
	printf("x * y = %.2lf \n",mymul(x,y));
	printf("x / y = %.2lf \n",mydiv(x,y));

	return 0;
}
