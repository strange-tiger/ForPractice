#include <stdio.h>
#include <stdarg.h>

// myprintf(3, 1, 2, 3) => My Variadic Function : 1, 2, 3
// "My Variadic Function : ~"
//void myprintf(int count, ...)
//{
//    va_list args;                        // <stdarg.h>
//    va_start(args, count);               // <stdarg.h>
//    
//    printf("My Variadic Function :");
//    for (int i = 0; i < count; ++i)
//    {
//        int number = va_arg(args, int); // <stdarg.h>
//        printf(" %d,", number);
//    }
//
//    va_end(args);                       // <stdarg.h>
//}



// <summary>
// printf와 유사하게 동작하나 기능이 제한됨.
// %d / %c / %f / %s
// </summary>
// <param name="format">형식 문자열</param>
// <param name="">가변 인자값</param>
void myprintf(const char* format, ...);

int main(void)
{
	//myprintf(5, 1, 2, 3, 4, 5);
	//
	//struct S { char ch; double d; float f; } s = {0, 0, 0}; // 패딩 발생
	////alignof(s);
	//
	//sizeof(struct { char ch; float d; float f; });  // 패딩 해결
	//sizeof(struct { char ch; float f; double d; });  // 패딩 해결
	//
	//// 패딩은 멤버의 정렬 요건 중 가장 큰 값으로 맞추게 된다.
	//// 패딩을 줄이려면 크기가 작은 것부터 큰 순서대로, 혹은 큰 것부터 작은 순서대로 정의하면
	//// 가장 최소한의 패딩 바이트를 얻는다.
	//
	//union Color
	//{
	//    struct
	//    {
	//        unsigned char R;    //  1바이트
	//        unsigned char G;    //  1바이트
	//        unsigned char B;    //  1바이트
	//        unsigned char A;    //  1바이트
	//    };
	//    unsigned int Value; //  4바이트
	//};
	//
	// 공용체
	//union Color color;
	//color.R = 0;
	//color.G = 47;
	//color.B = 167;
	//color.B = 255;
	//// 클라인 블루
	//color.Value = 0xFFAB4700;
	//// 멤버 중 가장 큰 크기의 데이터를 가지고 나눠쓰는 구조체
	myprintf("Hello My Printf : %d, %c, %s", 10000, 'A', "Hello");
	putchar('\n');
	myprintf("Hello My Printf : %d, %c, %s", -10000, 'z', "Olleh");
	// Output : Hello My Printf : 10, A, Hello

	return 0;
}

void myprintf(const char* format, ...)
{
	va_list args;	// 가변 인자를 다룰 객체를 만든다.
	va_start(args, format);	// 가변 인자의 시작 위치를 알려준다.

	/*char* str;
	str = format;*/
	while (*format != '\0')
	{
		if (*format == '%')
		{
			//putchar(' ');

			if (*(format + 1) == 'd')
			{
				int i = va_arg(args, int);	// 인자를 빼서 사용한다.

				if (i == 0)
				{
					putchar(i + '0');
				}
				else
				{
					int digit[256] = { 0 };
					// int* Digit = digit; // 동적 할당 malloc

					int count = 0;
					if (i < 0)
					{
						putchar('-');
						i *= -1;
					}
					while (i != 0)
					{
						digit[count] = i % 10;
						// *(Digit + count) = i % 10;
						// Digit++;
						count++;
						
						i /= 10;
					}

					for (int k = count - 1; k >= 0; k--)
					{
						putchar(digit[k] + '0');
					}
					//for (int k = count - 1; k >= 0; k--)
					//{
					//	putchar(*(Digit + k) + '0');
					//}

					/*
					int tendigit = i / 10;
					int onedigit = i % 10;
					putchar(tendigit + '0');
					putchar(onedigit + '0');
					*/
				}
			}
			else if (*(format + 1) == 'c')
			{
				char c = va_arg(args, char);
				putchar(c);
			}
			else if (*(format + 1) == 's')	// 오답노트 안건 : 문자열 리터럴("Hello")은 데이터 영역 (변경 불가)에 저장되며, ""은 그 주소값을 보낸다
			{
				char* s = va_arg(args, char*);
				//s = "Hello";
				for (int k = 0; *(s + k) != '\0'; k++)
				{
					putchar(*(s + k));
				}
			}
			/*if (*(format + 2) != '\0')
			{
				putchar(',');
			}*/
			++format;
		}
		else
		{
			putchar(*format);
		}
		++format;
	}

	va_end(args);	// 끝낸다.
}
