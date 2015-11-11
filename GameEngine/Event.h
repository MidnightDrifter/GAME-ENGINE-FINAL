#ifndef EVENT_H
#define EVENT_H


enum EventType
{
	COLLISION_EVENT,
	PLAYER_HIT_EVENT,


	NUM


};


class Event
{
public:
	Event() : eType(NUM), timer(0.0f) {}
	Event(EventType t) : eType(t), timer(0.0f) {}
	int getEventType() { return eType; }
	void setEventType(EventType t) { eType = t; }
	virtual ~Event();
	float getTimer() { return timer; }
	void setTimer(float t) { timer = t; }
	void decrementTimer(float t) { timer -= t; }

private:
	EventType eType;
	float timer;
};
#endif
