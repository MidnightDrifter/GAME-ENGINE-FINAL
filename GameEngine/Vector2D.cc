#include "Vector2D.h"

#define EPSILON 0.0001
#include <math.h>
#define PI      3.1415926535897932384626433832795
// ---------------------------------------------------------------------------

void Vector2DZero(Vector2D *pResult)
{
    pResult->x=0;
    pResult->y=0;


}

// ---------------------------------------------------------------------------

void Vector2DSet(Vector2D *pResult, float x, float y)
{
    pResult->x=x;
    pResult->y=y;


}

// ---------------------------------------------------------------------------

void Vector2DNeg(Vector2D *pResult, Vector2D *pVec0)
{
    pResult->x = (pVec0->x)*-1;
    pResult->y = (pVec0->y)*-1;


}

// ---------------------------------------------------------------------------

void Vector2DAdd(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1)
{
    pResult->x = (pVec0->x)+(pVec1->x);
    pResult->y = (pVec0->y)+(pVec1->y);


}

// ---------------------------------------------------------------------------

void Vector2DSub(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1)
{

    Vector2DNeg(pVec1, pVec1);
    Vector2DAdd(pResult, pVec0, pVec1);

}

// ---------------------------------------------------------------------------

void Vector2DNormalize(Vector2D *pResult, Vector2D *pVec0)
{
    float temp = sqrt((pow(pVec0->x, 2))+pow(pVec0->y,2));
    pResult->x = pVec0->x / temp;
    pResult->y = pVec0->y / temp;

}

// ---------------------------------------------------------------------------

void Vector2DScale(Vector2D *pResult, Vector2D *pVec0, float c)
{
    pResult->x = c*(pVec0->x);
    pResult->y = c*(pVec0->y);

}

// ---------------------------------------------------------------------------

void Vector2DScaleAdd(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1, float c)
{

    pResult->x = (c*pVec0->x)+(pVec1->x);
    pResult->y = (c*pVec0->y)+(pVec1->y);

}

// ---------------------------------------------------------------------------

void Vector2DScaleSub(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1, float c)
{
        pResult->x = (c*pVec0->x)-(pVec1->x);
        pResult->y = (c*pVec0->y)-(pVec1->y);

}

// ---------------------------------------------------------------------------

float Vector2DLength(Vector2D *pVec0)
{
	return sqrt(pow(pVec0->x,2) + pow(pVec0->y,2));
}

// ---------------------------------------------------------------------------

float Vector2DSquareLength(Vector2D *pVec0)
{
	return pow(pVec0->x,2) + pow(pVec0->y,2);
}

// ---------------------------------------------------------------------------

float Vector2DDistance(Vector2D *pVec0, Vector2D *pVec1)
{
	return sqrt(pow(pVec0->x - pVec1->x,2) + pow(pVec0->y - pVec1->y, 2));
}

// ---------------------------------------------------------------------------

float Vector2DSquareDistance(Vector2D *pVec0, Vector2D *pVec1)
{
	return pow(pVec0->x - pVec1->x, 2) + pow(pVec0->y - pVec1->y, 2);
}

// ---------------------------------------------------------------------------

float Vector2DDotProduct(Vector2D *pVec0, Vector2D *pVec1)
{
	return (pVec0->x * pVec1->x)+(pVec0->y * pVec1->y);
}

// ---------------------------------------------------------------------------

void Vector2DFromAngleDeg(Vector2D *pResult, float angle)
{  //Assuming this is a unit vector!
    angle = (180*angle) / PI;
    Vector2DFromAngleRad(pResult, angle);

}

// ---------------------------------------------------------------------------

void Vector2DFromAngleRad(Vector2D *pResult, float angle)
{//Assuming this is a unit vector!

    pResult->x = (cos(angle));
    pResult->y = (sin(angle));
}

// ---------------------------------------------------------------------------
