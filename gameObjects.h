/***********************************************************************
* Program:
*    GameObjects Header File
*    Brother Helfrich, CS165
* Author:
*    Nicholas Recht
* Summary: 
*   This file contains the class definitions for the GameObject class
*   and all of its children classes. 
************************************************************************/

#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "transform.h"
#include "point.h"
#include "uiDraw.h"
#include <vector>
#include <cmath>
#include "ai.h"
using namespace std;

#define PI 3.14159265

//GAMEPLAY BALANCERS
#define MISSILELAUNCH 5 //launch speed
#define BULLETLAUNCH 5
#define BULLETLIFETIME 240
#define SHIPTHRUST .2
#define SAUCERSHOOTTIME 30//time between successive shots
#define SHIPTURN 10 
#define MISSILETHRUST 1.0
#define MISSILETURN 15
#define MISSILESTOP .5 //maximum negative acceleration of the missle
#define MISSILESPEED 10 //maximum speed of a missile
#define DESTROYERSHOOTTIME 60//Time between successive shots
#define DESTROYERGUNSPACE 5 //Space between guns
#define DESTROYERGUNS 5 //Number of guns

class Asteroids; //forward declaration

//Base Class
class GameObject
{
  public:
  GameObject() : transform(), value(0) { };
  GameObject(const Transform & t) : transform(t), value(0) { };
   virtual void draw() = 0;
   virtual void increment(Asteroids & asteroids) = 0;
   virtual void destroy(Asteroids & asteroids) = 0;
   float getValue() const { return value; };
   Transform transform;
  protected:
   float value; //The lower the value the better
};

//Ship
class Ship : public GameObject
{
  public:
  Ship() : GameObject() { transform.setR(4); };
   virtual void draw();
   GameObject * fire();
   GameObject * fireMissile(list<GameObject*> & targets);
   void advance(int left, int right, int up, int down);
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
};

//Enemies
class Enemy : public GameObject
{
  public:
  Enemy() : GameObject() { };
  protected:
   
};

//Saucer
class Saucer : public Enemy
{
  public:
   Saucer(GameObject * player);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
   
  private:
   GameObject * fire();
   AI ai;
   int fireTime;
};

//Destroyer
class Destroyer : public Enemy
{
  public:
   Destroyer(GameObject * player);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
   
  private:
   GameObject * fire(Point p);
   AI ai;
   int fireTime;
};

//Small Asteroid
class AsteroidS : public Enemy
{
  public:
  AsteroidS() : Enemy() { transform.setAngle(random(0, 360)); transform.setDAngle(random(0, 20)); transform.setR(10); value = 2.0; };
   AsteroidS(const Point & pos);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
};

//Medium Asteroidc
class AsteroidM : public Enemy
{
  public:
  AsteroidM() : Enemy() { transform.setAngle(random(0, 360)); transform.setDAngle(random(0, 20)); transform.setR(20); value = 1.75; };
   AsteroidM(const Point & pos);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
};

//Large Asteroid
class AsteroidL : public Enemy
{
  public:
   AsteroidL();
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
};

//Bullet
class Bullet : public GameObject
{
  public:
  Bullet() : GameObject(), lifeTime(BULLETLIFETIME) { transform.setR(1); };
   Bullet(Transform & t);
   Bullet(Transform & t, Point p);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
  private:
   int lifeTime;
};

//Missile
class Missile : public GameObject
{
  public:
   Missile(Transform & t, list<GameObject*> & targets);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
  private:
   int lifeTime;
   AI ai;
   
};

//Debris
class Debris : public GameObject
{
  public:
  Debris() : GameObject(), lifeTime(30) { transform.setR(3); };
   Debris(Transform & t);
   virtual void draw();
   virtual void increment(Asteroids & asteroids);
   virtual void destroy(Asteroids & asteroids);
  private:
   int lifeTime;
};


#endif //GAMEOBJECTS_H
