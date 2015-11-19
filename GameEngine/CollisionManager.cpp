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


int CollisionManager::Shape::getShapeType()
{
	return shapeType;
}

void CollisionManager::Shape::setShapeType(ShapeType s)
{
	shapeType = s;
}


void CollisionManager::CheckCollisionAndGenerateContacts(Shape* a, float ax, float ay, Shape* b, float bx, float by)
{
	Vector2D aPos, bPos;
	aPos.x = ax;
	aPos.y = ay;
	bPos.x = bx;
	bPos.y = by;
	return CheckCollisionAndGenerateContacts(a, aPos, b, bPos);
}

void CollisionManager::CheckCollisionAndGenerateContacts(Shape* a, Vector2D aPos, Shape* b, Vector2D bPos)
{
	bool temp = ShapeShapeCollision(a, aPos, b, bPos);
}


bool CollisionManager::CircleRectangleCollision(ShapeCircle* circle, float cx, float cy, ShapeRectangle* rect, float rx, float ry)
{
	Vector2D rPos, cPos;
	rPos.x = rx;
	rPos.y = ry;
	cPos.x = cx;
	cPos.y = cy;

	return CircleRectangleCollision(circle, cPos, rect, rPos);
}

bool CollisionManager::CircleRectangleCollision(ShapeRectangle* rect, float rx, float ry, ShapeCircle* circle, float cx, float cy)
{
	return CircleRectangleCollision(circle, cx, cy, rect, rx, ry);
}

bool CollisionManager::CircleRectangleCollision(ShapeRectangle* rect, Vector2D rPos, ShapeCircle* circle, Vector2D cPos)

{
	return CircleRectangleCollision(circle, cPos, rect, rPos);
}

bool CollisionManager::CircleRectangleCollision(ShapeCircle* circle, Vector2D cPos, ShapeRectangle* rect, Vector2D rPos)
{
	if( StaticCircleToStaticRectangle(&cPos, circle->getRadius(), &rPos, rect->getWidth(), rect->getHeight()))
	{
		return true;
	}

return false;

	
}

bool CollisionManager::RectangleRectangleCollision(ShapeRectangle* r1, float r1x, float r1y, ShapeRectangle* r2, float r2x, float r2y)
{
	Vector2D r1Pos, r2Pos;
	r1Pos.x = r1x;
	r1Pos.y = r1y;
	r2Pos.x = r2x;
	r2Pos.y = r2y;
	return RectangleRectangleCollision(r1, r1Pos, r2, r2Pos);
	
}

bool CollisionManager::RectangleRectangleCollision(ShapeRectangle* r1, Vector2D r1Pos, ShapeRectangle* r2, Vector2D r2Pos)
{
	if(StaticRectToStaticRect(&r1Pos, r1->getWidth(), r1->getHeight(), &r2Pos, r2->getWidth(), r2->getHeight()))
	{
		return true;
	}
	return false;
}

bool CollisionManager::CircleCircleCollision(ShapeCircle* c1, float cx, float cy, ShapeCircle* c2, float c2x, float c2y)
{
	Vector2D c1Pos, c2Pos;
	c1Pos.x = cx;
	c1Pos.y = cy;
	c2Pos.x = c2x;
	c2Pos.y = c2y;

	return CircleCircleCollision(c1, c1Pos, c2, c2Pos);
}

bool CollisionManager::CircleCircleCollision(ShapeCircle* c1, Vector2D c1Pos, ShapeCircle* c2, Vector2D c2Pos)
{
	if(StaticCircleToStaticCircle(&c1Pos, c1->getRadius(), &c2Pos, c2->getRadius()))
	{
		return true;
	}
	return false;
}

bool CollisionManager::ShapeShapeCollision(Shape* a, float ax, float ay, Shape* b, float bx, float by)
{
	Vector2D aPos, bPos;
	aPos.x = ax;
	aPos.y = ay;
	bPos.x = bx;
	bPos.y = by;
	return ShapeShapeCollision(a, aPos, b, bPos);
}

bool CollisionManager::ShapeShapeCollision(Shape* a, Vector2D aPos, Shape* b, Vector2D bPos)
{
	if (a->getShapeType() == CollisionManager::Shape::CIRCLE)
	{
		if (b->getShapeType() == CollisionManager::Shape::CIRCLE)
		{
			return((CircleCircleCollision(static_cast<ShapeCircle*>(a), aPos, static_cast<ShapeCircle*>(b), bPos)));
		}

		else
		{
			return(CircleRectangleCollision(static_cast<ShapeCircle*>(a), aPos, static_cast<ShapeRectangle*>(b), bPos));
		}
	}

	else
	{
		if(b->getShapeType() == CollisionManager::Shape::CIRCLE)
		{
			return (CircleRectangleCollision(static_cast<ShapeCircle*>(b), bPos, static_cast<ShapeRectangle*>(a), aPos));
		}

		else
		{
			return (RectangleRectangleCollision(static_cast<ShapeRectangle*>(a), aPos, static_cast<ShapeRectangle*>(b), bPos));
		}
	}
}


/*  Before Phyisics stuff:




for (auto i : CollisionManager.contacts)
{
	CollideEvent collideEvent;
	collideEvent.g1 = i->contacts[0]->owner;
	collideEvent.g2 = i->contacts[1]->owner;

	collideEvent.g1->HandleEvent(&collideEvent);
	collideEvent.g2->HandleEvent(&collideEvent);
}






*/



/*Physics stuff goes here?
*
*
*
*
*
*
*
*/