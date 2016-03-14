/***********************************************************************
* Program:
*    Transform Class Source File 
*    Brother Helfrich, CS165
* Author:
*    Nicholas Recht
* Summary: 
*    This file contains all of the definitions for the Transform Class
*    contained in the transform.h header. 
************************************************************************/

#include "transform.h"
#include "point.h"
#include <cmath>
using namespace std;

/**********************************************************************
 * TRANSFORM::CHECKBOUNDS  checks the position of the object to make sure
 *                      it is within bounds
 ***********************************************************************/
void Transform::checkBounds()
{
   if (pos.getX() > pos.getXMaxBounds() ||
       pos.getX() < pos.getXMinBounds() ||
       pos.getY() > pos.getYMaxBounds() ||
       pos.getY() < pos.getYMinBounds())
      bounds = true;

   else
      bounds = false;
}

/**********************************************************************
 * TRANSFORM::WWRAP  applies a wrap to the transform's coordinates
 ***********************************************************************/
void Transform::wrap()
{
   float x = getX();
   float y = getY();
   float xMax = getPos().getXMax();
   float yMax = getPos().getYMax();
   float xMin = getPos().getXMin();
   float yMin = getPos().getYMin();
          
   if (x > xMax)
      setX(x - 2 * xMax);
   if (x < xMin)
      setX(x + 2 * xMax);
   if (y > yMax)
      setY(y - 2 * yMax);
   if (y < yMin)
      setY(y + 2 * yMax);   
}

/**********************************************************************
 * TRANSFORM::CHECKCOLLISION  checks the vector of the member object against
 *                         another object see if they collide
 *                         Inpust thatObject -> object to check against
 ***********************************************************************/
void Transform::checkCollision(const Transform & thatObject)
{
   float max = maximum(maximum(abs(dx), abs(thatObject.dx)),
                       maximum(abs(dy), abs(thatObject.dy)));
   float distanceSquared = 0.;
   float min = 99999.;
   
   for (int i = max; i > 0; i--)
   {
      distanceSquared = pow((pos.getX() + dx * i / max) -
                            (thatObject.pos.getX() + thatObject.dx * i / max), 2) +
                        pow((pos.getY() + dy * i / max) -
                            (thatObject.pos.getY() + thatObject.dy * i / max), 2);
      min = minimum(distanceSquared, min);
   }

   min = sqrt(min);

   if (min < (r + thatObject.r))
      collided = true;

   return;
   
}

float Transform::getSpeed() const
{
   return sqrt(dx * dx + dy * dy);
}

/**********************************************************************
 * TRANSFORM::MOVE  moves the object according to accleration, velocity and
 *               angular velocity
 ***********************************************************************/
void Transform::move()
{
   if (angle > 360)
      angle -= 360;

   if (angle < 0)
      angle += 360;
   
   dx += ax;
   dy += ay;

   pos.setX(pos.getX() + dx);
   pos.setY(pos.getY() + dy);

   dAngle += aAngle;
   angle += dAngle;
}

/**********************************************************************
 * TRANSFORM::SETPOS  sets the position of the object
 *                 Input: x-> x coordinate to set
 *                        y-> y coordinate to set
 ***********************************************************************/
bool Transform::setPos(float x, float y)
{
   pos.setX(x);
   pos.setY(y);

   return true;
}

/**********************************************************************
 * OBJECT::SETPOS  sets the position of the object
 *                 Input: p-> point to copy to object
 ***********************************************************************/
bool Transform::setPos(Point p)
{
   pos.setX(p.getX());
   pos.setY(p.getY());

   return true;
}

/**********************************************************************
 * TRANSFORM::SETX  sets the x position of the object
 *               Input: x-> x coordinate to set to
 ***********************************************************************/
bool Transform::setX(float x)
{
   pos.setX(x);

   return true;
}

/**********************************************************************
 * TRANSFORM::SETY  sets the y position of the object
 *               Input: y-> y coordinate to set to
 ***********************************************************************/
bool Transform::setY(float y)
{
   pos.setY(y);

   return true;
}

/**********************************************************************
 * TRANSFORM::SETANGLE  sets the angle of the object
 *                   Input: angle-> angle to set to
 ***********************************************************************/
bool Transform::setAngle(float angle)
{
   this->angle = angle;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETR  sets the radius of the object
 *               Input: r-> radius to set to
 ***********************************************************************/
bool Transform::setR(float r)
{
   this->r = r;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETDANGLE  sets the angular speed of the object
 *                    Input: dAngle-> angular speed to set to
 ***********************************************************************/
bool Transform::setDAngle(float dAngle)
{
   this->dAngle = dAngle;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETAANGLE  sets the angular acceleration of the object
 *                    Input: aAngle-> angular acceleration to set to
 ***********************************************************************/
bool Transform::setAAngle(float aAngle)
{
   this->dAngle = dAngle;

   return true;
}

/**********************************************************************
 * OBJECT::SETAX  sets the x acceleration of the object
 *               Input: ax-> x acceleration to set to
 ***********************************************************************/
bool Transform::setAX(float ax)
{
   this->ax = ax;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETAY  sets the y acceleration of the object
 *                Input: ay-> y acceleration to set to
 ***********************************************************************/
bool Transform::setAY(float ay)
{
   this->ay = ay;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETDX  sets the x velocity of the object
 *                Input: dx-> x velocity to set to
 ***********************************************************************/
bool Transform::setDX(float dx)
{
   this->dx = dx;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETDY  sets the y velocity of the object
 *                Input: dy-> y velocity to set to
 ***********************************************************************/
bool Transform::setDY(float dy)
{
   this->dy = dy;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETCOLLIDED  sets the collision state of the object
 *                      Input: isCollided-> collision state to set to
 ***********************************************************************/
bool Transform::setCollided(bool isCollided)
{
   this->collided = isCollided;

   return true;
}

/**********************************************************************
 * TRANSFORM::SETBOUNDS  sets the bounds state of the object
 *                      Input: isBounds-> bounds state to set to
 ***********************************************************************/
bool Transform::setBounds(bool isBounds)
{
   this->bounds = isBounds;

   return true;
}

/**********************************************************************
 * MAXIMUM  compares two numbers and returns the maximum
 *          Input: a-> first number
 *                 b-> second number
 *          Ourput: The greater of the two numbers
 ***********************************************************************/
float maximum(float a, float b)
{
   if (a > b)
      return a;
   else
      return b;
}

/**********************************************************************
 * MAXIMUM  compares two numbers and returns the maximum
 *          Input: a-> first number
 *                 b-> second number
 *          Ourput: The greater of the two numbers
 ***********************************************************************/
int maximum(int a, int b)
{
   if (a > b)
      return a;
   else
      return b;
}

/**********************************************************************
 * MINIMUM  compares two numbers and returns the minimum
 *          Input: a-> first number
 *                 b-> second number
 *          Ourput: The lesser of the two numbers
 ***********************************************************************/
float minimum(float a, float b)
{
   if (a < b)
      return a;
   else
      return b;
}

/**********************************************************************
 * MINIMUM  compares two numbers and returns the minimum
 *          Input: a-> first number
 *                 b-> second number
 *          Ourput: The lesser of the two numbers
 ***********************************************************************/
int minimum(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}

