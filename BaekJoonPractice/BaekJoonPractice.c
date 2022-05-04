#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hanoiTowerNum(int N/*, int start, int dest, int bypass*/)
{
	int num = N;
	int count = 0;

	if (N == 1)
	{
		count = 1;
	}
	else
	{
		count = 2 * hanoiTowerNum(N - 1) + 1;
	}

	return count;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int countMove = hanoiTowerNum(N);
	printf("%d\n", countMove);
	
	return 0;
}