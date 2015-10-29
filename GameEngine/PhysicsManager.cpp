#include "PhysicsManager.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Body.h"

#define GRAVITY 200.0f
extern GameObjectManager GameObjectMgr;

PhysicsManager::PhysicsManager()
{
}


PhysicsManager::~PhysicsManager()
{
}



void PhysicsManager::update(float dTime)
{
	GameObject* pObj = NULL;
	for (int i = GameObjectMgr.gameObjects->capacity() - 1; i >= 0; i--)

	{
		pObj = GameObjectMgr.gameObjects->at(i);

		Body* b = static_cast<Body*>(pObj->getBody());

		if (b)
		{
			b->Integrate(GRAVITY, dTime);
		}
	}


}