#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include "Event.h"
#include "GameObjectManager.h"
#include <list>

class EventManager
{
	friend class GameObjectManager;


public:
	EventManager() : timedEvents(NULL) {}
	~EventManager() {
		for (auto i : timedEvents)
		{
			delete i;
		}
		timedEvents.clear();
	}


	 void BroadcastEvent(Event* pE); 
	 void AddTimedEvent(Event* t);   //Set default time to 0 for instantaneous events
	 void Update(float frameTime);

private:
	std::list<Event*> timedEvents;


};
#endif
