#include "FramerateController.h"
#include "..\..\SDL\include\SDL_timer.h"


FramerateController::FramerateController(Uint32 maxFramerate)
{
	maxFramerate = maxFramerate;
	//in ms so
	ticksPerFrame = 1000 / maxFramerate;
	tickStart = 0;
	tickEnd = 0;
	frameTime = 0;



}


void FramerateController::FrameStart()
{
	tickStart = SDL_GetTicks();
}


void FramerateController::FrameEnd()
{
	tickEnd = SDL_GetTicks();

	while (tickEnd - tickStart < ticksPerFrame)
	{
		tickEnd = SDL_GetTicks();

	}


	frameTime = tickEnd - tickStart;
}


Uint32 FramerateController::getFrameTime()
{
	return frameTime;
}
FramerateController::~FramerateController()
{
}
