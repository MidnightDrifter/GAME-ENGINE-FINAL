#include "Component.h"
#include "GameObject.h"


Component::Component()
{
	type = -1;
	owner = NULL;
}

Component::Component(int t)
{
	type = t;
	owner = NULL;

}

Component::Component(GameObject* g)
{
	owner = g;
	type = -1;

}

Component::Component(int t, GameObject* g)
{
	owner = g;
	type = t;

}

GameObject* Component::getOwner()
{
	return owner;
}

void Component::setOwner(GameObject* g)
{

	owner = g;

}

void Component::setType(int t)
{

	type = t;

}


int Component::getType()
{
	return type;

}


void Component::update()
{

}





Component::~Component()
{
}

void Component::serialize(FILE** fpp)
{

}
