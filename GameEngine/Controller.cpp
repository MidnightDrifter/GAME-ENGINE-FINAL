#include "Component.h"
#include "Controller.h"
#include "InputManager.h"
#include "Transform.h"
#include "GameObject.h"
#include "..\..\SDL\include\SDL.h"
#include "PhysicsManager.h"
extern InputManager InputMgr;

Controller::Controller()
{
	type = COMPONENT_TYPE_CONTROLLER;
}


Controller::~Controller()
{
}



void Controller::Update()
{
	if (owner != NULL)
	{

		Component* c = owner->getComponent(COMPONENT_TYPE_TRANSFORM);
		Transform* t = dynamic_cast<Transform*>(c);

		if (t != NULL)

			if (InputMgr.isKeyPressed(SDL_SCANCODE_UP))
			{
				//Move up when up is pressed
				t->addToY(3);
			}


			else if (InputMgr.isKeyPressed(SDL_SCANCODE_DOWN))
			{
				//Move up when up is pressed
				t->subToY(3);
			}


		if (InputMgr.isKeyPressed(SDL_SCANCODE_LEFT))
		{
			//Move up when up is pressed
			t->subToX(3);
		}

		else if (InputMgr.isKeyPressed(SDL_SCANCODE_RIGHT))
		{
			//Move up when up is pressed
			t->addToX(3);
		}





	}
}
	void Controller::Update(Transform* t)
	{


		if (t != NULL)

		{
			if (InputMgr.isKeyPressed(SDL_SCANCODE_UP))
			{
				//Move up when up is pressed
				t->addToY(-3);
			}


			else if (InputMgr.isKeyPressed(SDL_SCANCODE_DOWN))
			{
				//Move up when up is pressed
				t->subToY(-3);
			}


			if (InputMgr.isKeyPressed(SDL_SCANCODE_LEFT))
			{
				//Move up when up is pressed
				t->subToX(3);
			}

			else if (InputMgr.isKeyPressed(SDL_SCANCODE_RIGHT))
			{
				//Move up when up is pressed
				t->addToX(3);
			}

		}

	}

	void Controller::serialize(FILE** fpp)
	{

	}



	void Controller::handleEvent(Event* t)
	{
		if (t->getEventType() == EventType::COLLISION_EVENT)
		{
			PhysicsManager::CollideEvent* cE = static_cast<PhysicsManager::CollideEvent*>(t);
		}

		Transform* tP = static_cast<Transform*>(owner->getTransform());

		//Do something with event

		if (tP)
		{
			//Do something with event here, i.e. reset xPos
			tP->setX(0.0f);

		}
	}
