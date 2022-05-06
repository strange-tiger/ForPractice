// 오답노트 // 백준 11729 하노이탑 // 재귀적 규칙 찾기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoiTower(int N, int start, int dest, int bypass)
{

	if (N == 1)
	{
		printf("%d %d\n", start, dest);
	}
	else
	{
		hanoiTower(N - 1, start, bypass, dest);
		printf("%d %d\n", start, dest);
		hanoiTower(N - 1, bypass, dest, start);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int countMove = 1;
	countMove = countMove << N;
	countMove -= 1;

	printf("%d\n", countMove);

	hanoiTower(N, 1, 3, 2);

	return 0;
}


//// 오답노트 // 반복을 줄여보자
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//char word[1000001] = "";
//int main(void)
//{
//	int wordCount[26] = { 0 }; // 알파벳 26자의 개수를 a부터 z까지 순으로 받을 배열
//	scanf("%1000000s", word);
//
//	// 세어 가면서 최댓값을 찾는다.
//
//	int maxCount = 0;
//	char maxCountCh = 0;
//	for (int i = 0; word[i] != '\0'; i++)
//	{
//		const int DIFFERENCE_BETWEEN_UPPER_AND_LOWER = 'a' - 'A';
//		if (word[i] >= 'a') // 아스키 코드 대문자와 소문자의 차이 = 32
//		{
//			word[i] -= DIFFERENCE_BETWEEN_UPPER_AND_LOWER;
//		}
//
//		int chIndex = word[i] - 'A';
//
//		wordCount[chIndex]++;
//
//	if (maxCount < wordCount[chIndex])
//	{
//		maxCount = wordCount[chIndex];
//		maxCountCh = word[i];
//	}
//	else if (maxCount == wordCount[chIndex])
//	{
//		maxCountCh = '?';
//	}
//}
//printf("%c", maxCountCh);
//
//return 0;
//}