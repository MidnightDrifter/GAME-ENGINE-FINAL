#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H
#include "Event.h"

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
		CollideEvent() : Event(EventType::COLLISION_EVENT), g1(0), g2(0) {}
		~CollideEvent() {}

	private:
		GameObject* g1;
		GameObject* g2;

	};

private:


};

#endif