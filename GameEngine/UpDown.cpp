#include "UpDown.h"
#include "Transform.h"
#include "FramerateController.h"
#include "GameObject.h"
#include <stdio.h>

extern FramerateController FrameCrtl;

UpDown::UpDown()
{
	type = COMPONENT_TYPE_SPRITE;
	isUp = false;
}

UpDown::UpDown(bool i)
{
	isUp = i;
}

UpDown::UpDown(int t)
{
	timer = t;
		isUp = false;
}

UpDown::UpDown(bool i, int t)
{
	timer = t;
	isUp = i;
}


bool UpDown::getUp()
{

	return isUp;
}

void UpDown::setUp(bool i)
{
	isUp = i;

}

void UpDown::moveUp(int x)
{
	dynamic_cast<Transform*>(owner->getTransform())->addToY(x);

}

void UpDown::moveDown(int x)
{

	dynamic_cast<Transform*>(owner->getTransform())->subToY(x);
}

void UpDown::moveUp()
{
	moveUp(MOVE_DISTANCE);
}

void UpDown::moveDown()
{
	moveDown(MOVE_DISTANCE);

}


void UpDown::Update()
{
	Uint32 upCheck = 0; 
	Uint32 downCheck=0;
	if (isUp)
	{
		while (upCheck < timer)
		{
			upCheck += FrameCrtl.getFrameTime();
			moveUp(3);
		}

		setUp(false);

	}

	else
	{

		while (downCheck < timer)
		{

			downCheck += FrameCrtl.getFrameTime();
			moveDown(3);

		}
		setUp(true);

	}
}


void UpDown::Update(Transform* t)
{


	if (isUp)
	{
		if (upCheck < timer)
		{
			upCheck += FrameCrtl.getFrameTime();
			t->addToY(3);
		}

		else
		{
			upCheck = 0;
			isUp = false;
		}
	}

	


	else
{
	if (upCheck < timer)
	{
		upCheck += FrameCrtl.getFrameTime();
		t->subToY(3);
	}
	else
	{
		upCheck = 0;
		isUp = true;
	}
}

	

}

int UpDown::getTimer()
{
	return timer;
}

void UpDown::setTimer(int t)
{
	timer = t;
}

UpDown::~UpDown()
{
}


void UpDown::serialize(FILE** fpp)
{
	int flag;

	fscanf_s(*fpp, "%i %i\n", &flag, &timer);

	if(flag==0)
	{
		this->setUp(true);
	}

	else
	{
		this->setUp(false);
	}


}
