#include "App.h"

int main(void)
{
	// �ʱ�ȭ
	if (false == App_Init())
	{
		return 1;
	}

	return App_Run();
}