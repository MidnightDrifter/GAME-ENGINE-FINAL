#pragma once
#ifndef UPDOWN_H
#define UPDOWN_H

#include "Component.h"
#include "GameObject.h"
#include "Transform.h"

#define MOVE_TIME 2  //How many seconds an object will move up and down for--X sec up, X sec down, repeat
#define MOVE_DISTANCE 3.0f  //How far an object will move per frame
class UpDown :
	public Component
{
public:
	UpDown();
	UpDown(bool i);
	~UpDown();

	bool getUp();
	void setUp(bool i);
	void moveUp(int x);
	void moveDown(int x);
	void moveUp();
	void moveDown();
	void Update();
	void Update(Transform* t);

private:
	bool isUp;
	
};

#endif