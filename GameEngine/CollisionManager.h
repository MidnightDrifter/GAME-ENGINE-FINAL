



#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#pragma once

#include "Vector2D.h"
#include "Body.h"
#include <list>

class CollisionManager
{ 
public:
	
	class Shape {
	public:

		enum ShapeType
		{
			CIRCLE,
			RECTANGLE,


			NUM  //Stores total # of shapes
		};

		Shape() : owner(NULL), shapeType(NUM) {}
		Shape(ShapeType x) : owner(NULL), shapeType(x) {}
		virtual ~Shape() {}
		virtual bool TestPointCollision(float x, float y) = 0;
		virtual bool TestPointCollision(Vector2D position) = 0;
		Body* getOwner();
		void setOwner(Body* b);
		int getShapeType();
		void setShapeType(ShapeType s);

	protected:
		Body* owner;
		ShapeType shapeType;


	};



	class ShapeCircle : public Shape
	{
	public:
			ShapeCircle() :  Shape(CIRCLE), radius(0) {}
			ShapeCircle(float x) : Shape(CIRCLE), radius(x) {}
			~ShapeCircle() {}

			float getRadius();
			void setRadius(float x);
			bool TestPointCollision(float x, float y);
			bool TestPointCollision(Vector2D point);
			


	private:
		float radius;



	};


	class ShapeRectangle : public Shape
	{
	public:
		ShapeRectangle() : Shape(RECTANGLE), left(0), right(0), top(0), bottom(0) {}
		ShapeRectangle(float a, float b, float c, float d) : Shape(RECTANGLE), left(a), right(b), top(c), bottom(d) {}
		~ShapeRectangle() {}

		float getTop() const;
		float getBottom() const;
		float getLeft() const;
		float getRight() const;
		void setTop(float x);
		void setBottom(float x);
		void setLeft(float x);
		void setRight(float x);
		float getWidth() { return (left - right); }
		float getHeight() { return (top - bottom); }

		bool TestPointCollision(float x, float y);
		bool TestPointCollision(Vector2D position);

	private:
		float top, bottom, left, right;



	};

	
	class Contact
	{
	public:
		Contact() { bodies[0] = NULL;  bodies[1] = NULL; }
		~Contact() {}
	private:
		Body* bodies[2];
	};
	bool CircleRectangleCollision(ShapeCircle* circle, float cx, float cy, ShapeRectangle* rect, float rx, float ry);
	bool CircleRectangleCollision(ShapeCircle* circle, Vector2D cPos, ShapeRectangle* rect, Vector2D rPos);
	bool CircleRectangleCollision(ShapeRectangle* rect, float rx, float ry, ShapeCircle* circle, float cx, float cy);
	bool CircleRectangleCollision(ShapeRectangle* rect, Vector2D rPos, ShapeCircle* circle, Vector2D cPos);
	bool CircleCircleCollision(ShapeCircle* circle1, float c1x, float c1y, ShapeCircle* circle2, float c2x, float c2y);
	bool CircleCircleCollision(ShapeCircle* circle1, Vector2D c1Pos, ShapeCircle* circle2, Vector2D c2Pos);
	bool RectangleRectangleCollision(ShapeRectangle* rect1, float r1x, float r1y, ShapeRectangle* rect2, float r2x, float r2y);
	bool RectangleRectangleCollision(ShapeRectangle* rect1, Vector2D r1Pos, ShapeRectangle* rect2, Vector2D r2Pos);
		void CheckCollisionAndGenerateContacts(Shape* a, float ax, float ay, Shape* b, float bx, float by);
		void CheckCollisionAndGenerateContacts(Shape* a, Vector2D aPos, Shape* b, Vector2D bPos);

		bool ShapeShapeCollision(Shape* a, float ax, float ay, Shape* b, float bx, float by);
		bool ShapeShapeCollision(Shape* a, Vector2D aPos, Shape* b, Vector2D bPos);


	


	CollisionManager();
	~CollisionManager();

private:
	std::list<Contact*> contacts;
};

#endif