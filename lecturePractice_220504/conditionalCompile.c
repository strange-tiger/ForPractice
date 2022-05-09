//#include <stdio.h>
//
//int main(void)
//{
//#if 1
//	puts("1. 이건 실행됨");
//#endif
//
//#if defined(TEST)
//	puts("2. 이건 실행 안됨");
//#else
//	puts("이건 실행됨");
//#endif
//#if !defined(TEST)
//	puts("3. 이건 실행됨");
//#else
//	puts("3. 이건 실행 안됨");
//#endif
//
//#define TEST
//#ifdef TEST
//	puts("4. 이건 실행됨");
//#else
//	puts("4. 이건 실행 안됨");
//#endif
//
//#define T 10
//#ifndef TEST
//	puts("5. 이건 실행 안됨");
//#elif defined(T) && T > 2
//	puts("5. 이건 실행 됨");
//#else
//	puts("5. 이건 실행 안됨");
//#endif
//
//	return 0;
//}