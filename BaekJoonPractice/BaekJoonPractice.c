#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);

	char matrix[50][51];
	for (int i = 0; i < M; i++)
	{
		scanf("%s", matrix[i]);
	}

	int maxCount = 0;
	for (int i = 0; i <= M - 8; i++)
	{
		int count = 0;

		for (int j = 0; j <= N - 8; j++)
		{
			for (int k = i; k < i + 6; k++)
			{
				for (int l = j; l < j + 6; l++)
				{
					if (matrix[k][l] == matrix[k + 1][l] || matrix[k][l] == matrix[k][l + 1])
					{
						count++;
					}
				}
			}
			if (matrix[i + 6][j + 6] != matrix[i + 7][j + 7])
			{
				count++;
			}

			if (maxCount < count)
			{
				maxCount = count;
			}
		}
	}

	printf("%d", maxCount);

	return 0;
}