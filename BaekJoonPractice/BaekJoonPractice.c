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

	int minCount = 250;
	for (int i = 0; i < M - 7; i++)
	{

		for (int j = 0; j < N - 7; j++)
		{
			/*if (matrix[i][j] == 'W')
			{*/
			int count = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 1 && matrix[k][l] == 'W')
					{
						count++;
					}
					else if ((k + l) % 2 == 0 && matrix[k][l] == 'B')
					{
						count++;
					}
				}
			}
			//}

			if (minCount > count)
			{
				minCount = count;
			}
			count = 0;
			/*else if (matrix[i][j] == 'B')
			{*/
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 1 && matrix[k][l] == 'B')
					{
						count++;
					}
					else if ((k + l) % 2 == 0 && matrix[k][l] == 'W')
					{
						count++;
					}
				}
			}
			if (minCount > count)
			{
				minCount = count;
			}
			//}
		}
	}

	printf("%d", minCount);

	return 0;
}