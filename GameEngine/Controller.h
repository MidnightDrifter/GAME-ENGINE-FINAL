#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include <stdio.h>
#include "Event.h"
class Controller :
	public Component
{

	
public:
	Controller();
	~Controller();
	void Update();
	void Update(Transform* t);
	void serialize(FILE** fpp);
	void handleEvent(Event* p);
};


class PlayerHitEvent : public Event
{

public:
	PlayerHitEvent() : Event(PLAYER_HIT_EVENT) {}
	~PlayerHitEvent() {}
};


#endif