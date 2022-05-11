#include "Timer.h"
#include <time.h>

clock_t s_prevTime;
float s_deltaTime;
void Timer_Init(void)
{
	s_prevTime = clock();
}

void Timer_Update(void)
{
	clock_t currentTime = clock();

	float deltaTime = (float)(currentTime - s_prevTime) / CLOCKS_PER_SEC;

	s_deltaTime = deltaTime;
	s_prevTime = currentTime;
}

float Timer_GetDeltaTime(void)
{
	return s_deltaTime;
}