#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int cardNum[100] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &cardNum[i]);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (cardNum[i] + cardNum[j] + cardNum[k] <= M && cardNum[i] + cardNum[j] + cardNum[k] > sum)
				{
					sum = cardNum[i] + cardNum[j] + cardNum[k];
				}
			}
		}
	}
	printf("%d", sum);

	return 0;
}