#include <stdio.h>

unsigned int fibonacci(int n);
int main(void)
{
	printf("%d\n", fibonacci(45));

	return 0;
}

unsigned int fibonacci(int n)
{
	if(n < 2)
		return n;
	return fibonacci(n-1)+fibonacci(n-2);
}
