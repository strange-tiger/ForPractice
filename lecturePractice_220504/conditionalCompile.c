//#include <stdio.h>
//
//int main(void)
//{
//#if 1
//	puts("1. �̰� �����");
//#endif
//
//#if defined(TEST)
//	puts("2. �̰� ���� �ȵ�");
//#else
//	puts("�̰� �����");
//#endif
//#if !defined(TEST)
//	puts("3. �̰� �����");
//#else
//	puts("3. �̰� ���� �ȵ�");
//#endif
//
//#define TEST
//#ifdef TEST
//	puts("4. �̰� �����");
//#else
//	puts("4. �̰� ���� �ȵ�");
//#endif
//
//#define T 10
//#ifndef TEST
//	puts("5. �̰� ���� �ȵ�");
//#elif defined(T) && T > 2
//	puts("5. �̰� ���� ��");
//#else
//	puts("5. �̰� ���� �ȵ�");
//#endif
//
//	return 0;
//}