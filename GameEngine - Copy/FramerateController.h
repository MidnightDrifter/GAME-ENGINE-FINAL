#pragma once
#include "..\..\SDL\include\SDL_timer.h"
#ifndef FRAMERATECONTROLLER_H
#define FRAMERATECONTROLER_H
class FramerateController
{
public:
	FramerateController(Uint32 maxFramerate);
	~FramerateController();

	Uint32 getFrameTime();

	void FrameStart();
	void FrameEnd();


private:
	Uint32 tickStart;
	Uint32 tickEnd;
	Uint32 frameTime;
	Uint32 ticksPerFrame;
	Uint32 maxFramerate;

	
};

#endif