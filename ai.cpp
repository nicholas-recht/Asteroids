/***********************************************************************
* Program:
*    AI Class Source File
*    Brother Helfrich, CS165
* Author:
*    Nicholas Recht
* Summary: 
*    This file contains the class definitions for the AI class. 
************************************************************************/

#include "ai.h"
#include "transform.h"
#include "point.h"
#include <cmath>
#include "gameObjects.h"
#include <vector>
using namespace std;

/**********************************************************************
 * AI::GETDISTANCEBETWEEN:  Input: thisPoint, thatPoint
 *         Returns the distance between two points
 ***********************************************************************/
float AI::getDistanceBetween(Point thisPoint, Point thatPoint)
{  
   float distanceSquared = 0;
   distanceSquared = pow(thisPoint.getX() - thatPoint.getX(), 2) +
      pow(thisPoint.getY() - thatPoint.getY(), 2);

   return sqrt(distanceSquared);

}

/**********************************************************************
 * AI::GETANGLEBETWEEN  Input: thisPoint, thatPoint
 *          Returns the angle between two points from 0 to 360 degrees
 ***********************************************************************/
float AI::getAngleBetween(Point thisPoint, Point thatPoint)
{
   float angle = (atan2(thatPoint.getY() - thisPoint.getY(),
                        thatPoint.getX() - thisPoint.getX()) * 180 / PI);
   if (angle < 0)
      angle += 360;
   
   return angle;
}

/**********************************************************************
 * AI::INTERPOLATE  Input: thisObject, thatObject, speed
 *        Computes and returns the angle between two objects, based on
 *        their vectors, that will cause a projectile given at the
 *        inputed speed to intersect within a maximum of 120 frames
 ***********************************************************************/
float AI::interpolate(const GameObject * thisObject, const GameObject * thatObject, float speed) 
{
   //Our combined dv
   float dx = thatObject->transform.getDX() + -thisObject->transform.getDX();
   float dy = thatObject->transform.getDY() + -thisObject->transform.getDY(); 
   
   int i = 0;
   while (getDistanceBetween(thisObject->transform.getPos(),
                             Point(thatObject->transform.getPos(),i * dx ,i * dy)) > speed * i && i < 60)
      i++;
   //Loop until we get to a point where the bullet can hit
   i--; 
   
   return getAngleBetween(thisObject->transform.getPos(),
                          Point(thatObject->transform.getPos(), i * dx, i * dy));
}

/**********************************************************************
 * AI::FINDTARGET  Input: reference, targets
 *        Sets the this->target to a pointer to a target based on the
 *        vector of given targets and a reference object. 
 ***********************************************************************/
void AI::findTarget(GameObject * reference, list<GameObject*> & targets)
{
   float min = 99999.;
   for (list<GameObject*>::iterator it = targets.begin(); it != targets.end(); ++it)
   {
      float targetValue = 0; //lower is better
      targetValue += getDistanceBetween(reference->transform.getPos(), (*it)->transform.getPos());
      targetValue += abs(reference->transform.getAngle() -
                         getAngleBetween(reference->transform.getPos(),
                                         (*it)->transform.getPos())) * 2;
      targetValue *= (*it)->getValue();
      min = minimum(min, targetValue);
      if (min == targetValue)
         target = (*it);
   }
}
