#include "Body.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"


Body::Body()
{
	currentPos.x = 0;
	currentPos.y = 0;
	previousPos.x = 0;
	previousPos.y = 0;
	force.x = 0;
	force.y = 0;
	mass = 0;
	inverseMass = 1;
}


Body::Body(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k)
{
	type = COMPONENT_TYPE_BODY;

	currentPos.x = a;
	currentPos.y = b;
	previousPos.x = c;
	previousPos.y = d;
	velocity.x = e;
	velocity.y = f;
	acceleration.x = g;
	acceleration.y = h;
	force.x = i;
	force.y = j;
	mass = k;

	if (mass)
	{
		inverseMass = 1.0f / mass;
	}
	else
	{
		inverseMass = 1;
	}
}

void Body::serialize(FILE** fpp)
{
	//Decide on format for this
}


void Body::Integrate(float gravity, float dTime)
{
	previousPos.x = currentPos.x;
	previousPos.y = currentPos.y;
	currentPos.x = velocity.x * dTime + currentPos.x;
	currentPos.y = velocity.y * dTime + currentPos.y;

	force.y = gravity;
	acceleration.x = force.x * mass;
	acceleration.y = force.y * mass;

	velocity.x = velocity.x + dTime * acceleration.x;
	velocity.y = velocity.y + dTime*acceleration.y;

	force.x = 0;
	force.y = 0;

	Transform* p = static_cast<Transform*>(this->owner->getTransform());

	if (p)
	{
		p->setX(currentPos.x);
		p->setY(currentPos.y);
	}

	
}


Body::~Body()
{
}
