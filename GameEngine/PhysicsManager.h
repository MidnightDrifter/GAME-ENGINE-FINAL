#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H
#include "Event.h"
#include "GameObject.h"
class PhysicsManager
{
	friend class GameObjectManager;
public:
	PhysicsManager();
	~PhysicsManager();
	void update(float dTime);

	class CollideEvent : public Event
	{
	public:
		CollideEvent() : Event(EventType::COLLISION_EVENT), g1(NULL), g2(NULL) {}
		~CollideEvent() {}

	private:
		GameObject* g1;
		GameObject* g2;

	};

private:


};

#endif