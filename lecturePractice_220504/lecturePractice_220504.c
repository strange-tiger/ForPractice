#include <stdio.h>

#include "MyHeaderFile.h"

// 매크로는 기호 상수처럼 사용할 수 있다.
#define SPEED_OF_LIGHT 299792458
// 함수처럼 사용할 수도 있다.
// 함수처럼 사용할 때는 매개변수에 꼭 ()를 사용하자.
#define MIN(a, b) ((a) < (b) ? (a) : (b))
// #을 붙여서 문자열 리터럴로 인식한다.
#define PRINT(msg) puts(#msg);
// 매개변수에 ##을 붙이면 문자끼리 잇는다.
#define DECLARE_MYTYPE(typename) struct MyTape##typename
// 가변 인자도 사용할 수 있다.
// 똑같이 문자열 리터럴로 인식이 된다.
// __VA_ARGS__는 ...이 들어갈 곳이다.
#define SIMPLE_PRINT(...) puts(#__VA_ARGS__)
#define FORMAT_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)
// #undef를 이용하면 정의했던 매크로를 해제할 수 있다.
// #undef SPEED_OF_LIGHT

// MSVC에서 미리 정의한 매크로도 있는데, 그 중 유용한 건 
// __FILE__, __LINE__, __DATE__, __TIME__ 정도가 있다.
#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
// 매크로를 잘 써야 C++도 C#처럼 생산성이 나온다.

int main(void)
{
	printf("빛의 속도는 %d m/s이다.\n", SPEED_OF_LIGHT);

	if (MIN(10 - 20, 20 < 4))
	{
		printf("10과 20 중 작은 수는 10입니다.");
	}

	PRINT(안녕하세요);

	DECLARE_MYTYPE(Student)
	{
		int a;
	} a;

	SIMPLE_PRINT(1, 'a', Hello);

	FORMAT_PRINT("Hello Macro : %d, %c, %s", 12, 'c', "Hello");
	
	printf("FILE : %s\n", __FILE__); // 파일 이름
	printf("FILE : %d\n", __LINE__); // 줄 번호
	printf("FILE : %s\n", __DATE__); // 날짜
	printf("FILE : %s\n", __TIME__); // 시간

	if (1)
	{
		PRINT_ERROR("오류가 발생했습니다.");
	}

	int a_ = 10;
	int b_ = 20;
	printf("Add_result = %d", Add(a_, b_));

	return 0;
}