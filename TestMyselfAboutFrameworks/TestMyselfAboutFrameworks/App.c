#include "App.h"
#include "Renderer.h"
#include "Timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

bool App_Init(void)
{
	if (false == Renderer_Init())
	{
		return false;
	}

	return true;
}

void processInput(void)
{

}

bool canShow = 0;
float elapsedTime = 0.0f;

void update(void)
{
	elapsedTime += Timer_GetDeltaTime();

	if (elapsedTime >= 0.5f)
	{
		elapsedTime = 0.0f;

		canShow = !canShow;
	}
}

void render(void)
{
	if (canShow)
	{
		Renderer_DrawText("Tests", sizeof("Tests"));
	}

	Renderer_Flip();

	Renderer_Clear();
}

int App_Run(void)
{
	Timer_Init();

	while (1)
	{
		Timer_Update();

		processInput();
		update();
		render();
	}
}