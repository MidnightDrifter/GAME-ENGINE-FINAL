#include "UpDown.h"
#include "Transform.h"
#include "FramerateController.h"
#include "GameObject.h"

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
		while (upCheck < MOVE_TIME)
		{
			upCheck += FrameCrtl.getFrameTime();
			moveUp(3);
		}

		setUp(false);

	}

	else
	{

		while (downCheck < MOVE_TIME)
		{

			downCheck += FrameCrtl.getFrameTime();
			moveDown(3);

		}
		setUp(true);

	}
}


void UpDown::Update(Transform* t)
{

	Uint32 upCheck = 0;
	Uint32 downCheck = 0;
	if (isUp)
	{
		while (upCheck < MOVE_TIME)
		{
			upCheck += FrameCrtl.getFrameTime();
			t->addToY(3);
		}

		setUp(false);

	}

	else
	{

		while (downCheck < MOVE_TIME)
		{

			downCheck += FrameCrtl.getFrameTime();
			t->subToY(3);

		}
		setUp(true);

	}

}


UpDown::~UpDown()
{
}
