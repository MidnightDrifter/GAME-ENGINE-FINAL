#pragma once
#ifndef UPDOWN_H
#define UPDOWN_H

#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Event.h"
#include "Controller.h"
#define MOVE_TIME 2000  //How many milliseconds an object will move up and down for--X sec up, X sec down, repeat
#define MOVE_DISTANCE 3.0f  //How far an object will move per frame
class UpDown :
	public Component
{
public:

	UpDown() :Component(COMPONENT_TYPE_UPDOWN), timer(MOVE_TIME), isUp(false), upCheck(0) {}
	
	UpDown(bool i);
	UpDown(int t);
	UpDown(bool i, int t);
	~UpDown();

	bool getUp();
	void setUp(bool i);
	void moveUp(int x);
	void moveDown(int x);
	void moveUp();
	void moveDown();
	void update();
	void update(Transform* t);
	void serialize(FILE** fpp);

	int getTimer();
	void setTimer(int t);


	void handleEvent(Event* t);


private:
	bool isUp;
	int upCheck;
	int timer;
	
};

#endif