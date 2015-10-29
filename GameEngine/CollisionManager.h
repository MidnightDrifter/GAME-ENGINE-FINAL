



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
		virtual bool TestPointCollision(float x, float y);
		virtual bool TestPointCollision(Vector2D position);
		Body* getOwner();
		void setOwner(Body* b);

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
			bool TestPointCollision(Vector2D position);
			


	private:
		float radius;



	};


	class ShapeRectangle : public Shape
	{
	public:
		ShapeRectangle() : Shape(RECTANGLE), left(0), right(0), top(0), bottom(0) {}
		ShapeRectangle(float a, float b, float c, float d) : Shape(RECTANGLE), left(a), right(b), top(c), bottom(d) {}
		~ShapeRectangle() {}

		float getTop();
		float getBottom();
		float getLeft();
		float getRight();
		void setTop(float x);
		void setBottom(float x);
		void setLeft(float x);
		void setRight(float x);

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
		void CheckCollisionAndGenerateContacts(Shape* a, float ax, float ay, Shape* b, float bx, float by);
		void CheckCollisionAndGenerateContacts(Shape* a, Vector2D aPos, Shape* b, Vector2D bPos);


	


	CollisionManager();
	~CollisionManager();

private:
	std::list<Contact*> contacts;
};

#endif