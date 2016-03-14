/***********************************************************************
* Program:
*    Project 2, Skeet 
*    Brother Helfrich, CS165
* Author:
*    Nicholas Recht
* Summary: 
*    This is the main driver program for Project 4, Asteroids. Contains the
*    main function and the callBack function for the openGl interface.
************************************************************************/

#include "uiInteract.h"
#include "uiDraw.h"
#include "asteroids.h"
using namespace std;

/**********************************************************************
 * CALLBACK
 * The main interaction loop of the engine. Calls the
 * Skeet ++ operator and the gun input functions.
 **********************************************************************/
void callBack(const Interface *pUI, void *p)
{
   Asteroids *pAsteroids = (Asteroids *)p;

   // Advance the Game
   (*pAsteroids)++;

   // Rotate the Gun
   pAsteroids->shipInput(pUI->isLeft(), pUI->isRight(), pUI->isUp(),
                    pUI->isDown(), pUI->isSpace());

}

/*********************************************************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it. Set up our callBack function.
 *********************************************************************/
int main(int argc, char **argv)
{
   // Start the drawing
   Interface ui(argc, argv, "Asteroids");

   // play the game.  Our function callback will get called periodically
   Asteroids asteroids;
   ui.run(callBack, (void *)&asteroids);

   return 0;
}
