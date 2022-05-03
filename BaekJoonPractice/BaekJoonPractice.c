#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hanoiTower(int N)
{
	int num = N;
	int count = 0;
	
	if (N == 1)
	{
		count = 1;
	}
	else
	{
		count = 2 * hanoiTower(N - 1) + 1;
	}

	return count;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int countMove = hanoiTower(N);

	printf("%d\n", countMove);
	return 0;
}                                  