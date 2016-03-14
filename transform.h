/***********************************************************************
* Program:
*    Transform Class Header 
*    Brother Helfrich, CS165
* Author:
*    Nicholas Recht
* Summary: 
*    This file contains the header for the Transform class. The transform
*    class contains all the data and functions needed for a moving
*    object. The object class contains no information for actually
*    drawing the objects, however it can move, check collisions with
*    other objects, and check if the object is out of bounds. 
************************************************************************/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "point.h"

class Transform
{
  public:
  Transform() : pos(), ax(0), ay(0), angle(0), dAngle(0), aAngle(0), dx(0),
      dy(0), r(0), collided(false), bounds(false) { /*intentionally empty*/};
    //Default Constructor
  Transform(const Transform & thatObject) : pos(thatObject.pos), ax(thatObject.ax),
      ay(thatObject.ay), angle(thatObject.angle), dAngle(thatObject.dAngle),
      aAngle(thatObject.aAngle), dx(thatObject.dx), dy(thatObject.dy),
      r(thatObject.r), collided(false), bounds(false){ /*intentionally empty*/};
    //Copy Constructor
   
   void move();
   void checkCollision(const Transform & thatObject);
   void checkBounds();
   void wrap();
   
   //Setters
   bool setPos(float x, float y);
   bool setPos(Point p);
   bool setX(float x);
   bool setY(float y);
   bool setAngle(float angle);
   bool setR(float r);
   bool setDAngle(float dAngle);
   bool setAAngle(float aAngle);
   bool setAX(float ax);
   bool setAY(float ay);
   bool setDX(float dx);
   bool setDY(float dy);
   bool setCollided(bool isCollided);
   bool setBounds(bool isBounds);

   //GETTERS
   float getAngle() const {return angle;};
   float getDAngle() const {return dAngle;};
   float getAAngle() const {return aAngle;};   
   Point getPos() const {return pos;};
   float getX() const {return pos.getX();};
   float getDX() const {return dx;};
   float getAX() const {return ax;};   
   float getY() const {return pos.getY();};
   float getDY() const {return dy;};
   float getAY() const {return ay;};
   float getR() const {return r;};
   float getSpeed() const;
   bool getCollided() const {return collided;};
   bool getBounds() const {return bounds;};
      
  private:
   Point pos;
   float ax; //acceleration in x
   float ay; //acceleration in y
   float angle; //angle facing
   float dAngle; //change in angle
   float dx; //change in x
   float dy; //change in y
   float r; //collision radius
   float aAngle; //acceleration in angle
   bool collided; //has collided
   bool bounds; //is out of bounds       
};

//Extra functions that are quite useful
//They aren't necessarily just used with objects, but I don't want to
//create a new header for just these.
float maximum(float a, float b);
int maximum(int a, int b);
float minimum(float a, float b);
int minimum(int a, int b);

#endif //TRANSFORM_H
