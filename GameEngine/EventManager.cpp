#include "EventManager.h"

extern GameObjectManager GameObjectMgr;




void EventManager::BroadcastEvent(Event* pE)
{
	for (auto i : *(GameObjectMgr.gameObjects))
	{
		i->handleEvent(pE);
	}

}



void EventManager::AddTimedEvent(Event* t)
{
	timedEvents.push_back(t);
}


void EventManager::Update(float frameTime)
{
	//Update times, if timer <= 0, broadcast event

	std::list<Event*>::iterator it, itTemp, itEnd;

	it = timedEvents.begin();
	itEnd = timedEvents.end();

	while (it!= itEnd)
	{
		Event* pE = *it;
		pE->decrementTimer(frameTime);
		if (pE->getTimer() <= 0)
		{
			BroadcastEvent(pE);
			delete(pE);

			itTemp = it;
			++itTemp;
			timedEvents.erase(it);
			it = itTemp;
		}

		else
		{
			++it;
		}
	}
}