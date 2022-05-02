#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci(int F)
{
	int f;

	if (F == 0 || F == 1)
	{
		f = F;
	}
	else
	{
		f = fibonacci(F - 1) + fibonacci(F - 2);
	}

	return f;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int result = fibonacci(N);

	printf("%d\n", result);

	return 0;
}