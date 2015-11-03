#include "CollisionManager.h"
#include "Math2D.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}


float CollisionManager::ShapeCircle::getRadius()
{
	return radius;
}

float CollisionManager::ShapeRectangle::getBottom() const
{
	return bottom;
}

Body* CollisionManager::Shape::getOwner()
{
	return owner;
}

void CollisionManager::Shape::setOwner(Body* b)
{
	owner = b;
}

void CollisionManager::ShapeCircle::setRadius(float f)
{
	radius = f;
}

void CollisionManager::ShapeRectangle::setBottom(float f)
{
	bottom = f;
}

void CollisionManager::ShapeRectangle::setTop(float f)
{
	top = f;
}

void CollisionManager::ShapeRectangle::setLeft(float f)
{
	left = f;
}

void CollisionManager::ShapeRectangle::setRight(float f)
{
	right = f;
}

float CollisionManager::ShapeRectangle::getRight() const
{
	return right;
}

float CollisionManager::ShapeRectangle::getLeft() const
{
	return left;
}

float CollisionManager::ShapeRectangle::getTop() const
{
	return top;
}


bool CollisionManager::ShapeRectangle::TestPointCollision(float x, float y)
{
	Vector2D temp;
	temp.x = x;
	temp.y = y;

	return TestPointCollision(temp);
}

bool CollisionManager::ShapeRectangle::TestPointCollision(Vector2D point)
{
	Vector2D t1, t2, rect;
	t1.x = left;
	t1.y = right;
	t2.x = top;
	t2.y = bottom;

	int width = Vector2DLength(&t1);
	int height = Vector2DLength(&t2);
	
	rect = owner->getCurrentPos();

	int temp = StaticPointToStaticRect(&point, &rect, width, height);

	if(temp==0)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool CollisionManager::ShapeCircle::TestPointCollision(float x, float y)
{
	Vector2D t;
	t.x = x;
	t.y = y;
	return TestPointCollision(t);

}

bool CollisionManager::ShapeCircle::TestPointCollision(Vector2D x)
{
	Vector2D circ = owner->getCurrentPos();

	int temp = StaticPointToStaticCircle(&x, &circ, radius);

	if (temp == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

