#pragma once
#ifndef UPDOWN_H
#define UPDOWN_H

#include "Component.h"
#include "GameObject.h"
#include "Transform.h"

#define MOVE_TIME 2000  //How many milliseconds an object will move up and down for--X sec up, X sec down, repeat
#define MOVE_DISTANCE 3.0f  //How far an object will move per frame
class UpDown :
	public Component
{
public:
	UpDown();
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
	void Update();
	void Update(Transform* t);
	void serialize(FILE** fpp);

	int getTimer();
	void setTimer(int t);
private:
	bool isUp;
	int upCheck;
	int timer;
	
};

#endif