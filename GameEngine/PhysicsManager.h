#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H
#pragma once
class PhysicsManager
{
	friend class GameObjectManager;
public:
	PhysicsManager();
	~PhysicsManager();
	void update(float dTime);

private:


};

#endif