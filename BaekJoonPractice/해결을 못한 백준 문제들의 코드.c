#pragma region 백준_1920_수찾기 // stack overflow // 퀵솔트(Quick Sort)?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int NUM_RANGE = 100000;
int A[NUM_RANGE] = { 0 };
int B[NUM_RANGE] = { 0 };

int abFind(int* a, int* b, int range, int* exist)
{
	int R = range;
	range == 0 ? R++ : R = range;

	if (*b == *(a + R / 2))
	{
		*exist = 1;
		return *exist;
	}
	else if (*b > *(a + R / 2))
	{
		abFind(a + R / 2, b, R / 2, exist);
	}
	else
	{
		abFind(a + R / 2, b, R / 2, exist);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 1; i < N; i++)
	{
		if (A[i - 1] > A[i])
		{
			int temp;
			temp = A[i - 1];
			A[i - 1] = A[i];
			A[i] = temp;
			i > 1 ? i -= 2 : i = 0;
		}
	}

	int M;
	scanf("%d", &M);

	int isExist = 0;
	int* exist;
	exist = &isExist;

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < M; i++)
	{
		abFind(A, B + i, N, exist);
		printf("%d\n", *exist);
	}


	return 0;
}

#pragma endregion

#pragma region 백준_10814_나이순 정렬 // 시간 초과 // 퀵솔트(Quick Sort)를 공부하고 재도전

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int age[100000] = { 0 };
char name[100000][100] = { 0 };

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &age[i], &name[i]);
	}

	for (int i = 1; i < N; i++)
	{
		if (age[i - 1] > age[i])
		{
			int tempAge;
			tempAge = age[i - 1];
			age[i - 1] = age[i];
			age[i] = tempAge;

			int strLength1 = *name[i - 1];
			int strLength2 = *name[i];

			int strLength;
			if (strLength1 > strLength2)
			{
				strLength = strLength1;
			}
			else
			{
				strLength = strLength2;
			}

			char tempName[100];
			for (int j = 0; j < strLength; j++)
			{
				tempName[j] = name[i - 1][j];
				name[i - 1][j] = name[i][j];
				name[i][j] = tempName[j];
			}
			if (i > 1)
			{
				i -= 2;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", age[i], name[i]);
	}

	return 0;
}

#pragma endregion