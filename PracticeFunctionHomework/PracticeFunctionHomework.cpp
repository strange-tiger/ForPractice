// strchr() : 문자열에서 특정 문자의 위치를 찾는 것
// 입력 : 문자열(const char*), 내가 찾을 문자(const char)
// 처리 : 입력된 문자열에서 그 문자가 나온 위치(메모리 주소)를 찾는다.
// 출력 : 문자의 위치 => 그 문자가 있는 메모리 주소값(char*)
// 1. 문자가 있는 경우 => 그 문자의 위치
// 2. 문자가 없는 경우 => NULL
// char* pos = strchr("Hello, 'l');
// "Hello"
//    ↑

// 1. 문제 정의 => 입력, 처리, 출력. 문제를 충분히 해결할 수 있을 정도로 계속해서 작은 단위로 쪼개서 생각해야 함.
// 2. 작은 문제로 쪼갰다면 그 문제를 해결할 절차를 기술.
// 3. 문제를 해결하기 위해 어떤 데이터가 필요한가? => 즉, 어떤 데이터를 저장해야 하는가?
#include <stdio.h>

char* strcpy(char* str1, char* str2)
{
	while (*str1 != '\0')
	{
		*str1 = *str2;
		++str1;
		++str2;
	}

	return str1;
}

char* strcat(char* str1, char* str2)
{
	while (*str1 != '\0')
	{
		++str1;
	}

	while (*str2 != '\0')
	{
		*str1 = *str2;
		++str1;
		++str2;
	}

	return str1;
}

unsigned int strlen(char* str)
{
	int strLength = 0;
	while (*str != '\0')
	{
		strLength++;
		++str;
	}

	return strLength;
}

int strcmp(char* str1, char* str2)
{
	int strCompare = 0;
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 > *str2 || (*str1 != '\0' && *str2 == '\0'))
		{
			strCompare = 1;
			return strCompare;
		}
		else if (*str1 < *str2 || (*str1 == '\0' && *str2 != '\0'))
		{
			strCompare = -1;
			return strCompare;
		}
		else if (*str1 == *str2)
		{
			++str1;
			++str2;
		}
	}
	return strCompare;
}

char* strchr(const char* str, const char ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return (char*)str;
		}

		++str;
	}

	return NULL;
}

char* strrchr(const char* str, const char ch)
{
	char* initstr = (char*)str;
	while (*str != '\0')
	{
		++str;
	}

	do
	{
		if (*str == ch)
		{
			return (char*)str;
		}

		--str;
	} while (str != initstr);

	return NULL;
}

char* strstr(const char* str, const char* substr)
{
	char* firstCh;
	/*if (*str == '\0')
	{
		return (char*)str;
	}
	else
	{*/
	while (*str != '\0')
	{
		if (*str == *substr)
		{
			int finder = 0;

			firstCh = (char*)str;
			while (*substr != '\0')
			{
				if (*str == *substr)
				{
					++str;
					++substr;
				}
				else
				{
					finder = 1;
					break;
				}
			}

			if (finder == 0)
			{
				return firstCh;
			}
		}

		++str;
	}
	//}
}

int main(void)
{
	char a[19] = "ababababa";
	char b[19] = "babababab";

	strcpy(a, b);
	strcat(a, b);
	int strLength = strlen(a);
	int strCompare = strcmp(a, b);
	int strCompare = strcmp(a, b);

	char* strFirstA = strchr(a, 'a');
	char* strFirstB = strchr(b, 'b');
	char* strLastA = strrchr(a, 'a');
	char* strLastB = strrchr(b, 'b');

	char c[4] = "a";
	char* strString = strstr(a, c);

	printf("%s\n", a);
	printf("%s\n", b);
	printf("%d\n", strLength);
	printf("%d\n", strCompare);
	printf("%c %c\n", *strFirstA, *strFirstB);
	printf("%c %c\n", *strLastA, *strLastB);

	printf("%s\n", strString);
	printf("%p\n", strString);
	printf("%p\n", a);
}