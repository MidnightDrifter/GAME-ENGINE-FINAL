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

Vector2D Body::getCurrentPos() const
{
	return currentPos;
}

void Body::setCurrentPos(Vector2D x)
{
	currentPos = x;
}

void Body::setCurrentPos(float x, float y)
{
	Vector2D a;
	a.x = x;
	a.y = y;
	setCurrentPos(a);
}


Vector2D  Body::getPreviousPos() const
{
	return previousPos;
}

void Body::setPreviousPos(Vector2D x)
{
	previousPos = x;
}

void Body::setPreviousPos(float x, float y)
{
	Vector2D a;
	a.x = x;
	a.y = y;
	setPreviousPos(a);
}


Vector2D Body::getAcceleration() const
{
	return acceleration;

}

void Body::setAcceleration(Vector2D a)
{
	acceleration = a;
}

void Body::setAcceleration(float a, float b)
{
	Vector2D x;
	x.x = a;
	x.y = b;
	setAcceleration(x);
}

Vector2D Body::getVelocity() const
{
	return velocity;
}


void Body::setVelocity(Vector2D a)
{
	acceleration = a;
}

void Body::setVelocity(float x, float y)
{
	Vector2D i;
	i.x = x;
	i.y = y;
	setVelocity(i);
}

Vector2D Body::getForce() const
{
	return force;
}

void Body::setForce(Vector2D a)
{
	force = a;
}

void Body::setForce(float a, float b)
{
	Vector2D x;
	x.x = a;
	x.y = b;
	setForce(x);
}


void Body::setMass(float a)
{
	mass = a;
	if(a)
	{
		inverseMass = 1.0 / a;
	}
	
	else
	{
		inverseMass = 1;
	}
}

float Body::getMass() const
{
	return mass;
}

float Body::getInverseMass() const
{
	return inverseMass;
}



Body::~Body()
{
}
