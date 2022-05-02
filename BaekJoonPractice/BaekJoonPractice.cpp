#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pactorial(int P)
{
	int p = 1;
	for (int i = 1; i <= P; i++)
	{
		p *= i;
	}

	return p;
}

int main(void)
{
	int N = 0;
	int K = 0;
	scanf("%d %d", &N, &K);
	
	int N_P = pactorial(N);
	int K_P = pactorial(K);
	int notK_P = pactorial(N - K);

	int result = N_P / (K_P * notK_P);

	printf("%d\n", result);

	return 0;
}