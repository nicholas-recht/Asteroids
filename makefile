########################################################################
# Program:
#    Project 4, Asteroids
#    Brother Helfrich, CS165
# Author:
#    Nicholas Recht
# Summary:
#    This program is a simple game that simulates the classic Atari game
#    Asteroids. The user controls a ship which is able to fly around
#    the screen using the arrow keys. The object of the game is to
#    destroy asteroids that drift randomly around the screen. The
#    player can fire shots using the space bar and dies if they collide
#    with an Asteroid.
# Extra Credit:
#    I added an expoding effect to all of the Asteroids and ships when
#    they die because it makes the whole game much more satisfying. I
#    also added multiple lives to the game and a basic HUD because it
#    makes the game longer. Players are immune during a 3 second respawn
#    time after they die. I also added homing missiles which can be fired
#    if one is available by holding the DOWN ARROW and clicking SPACE.
#    The homing missiles respawn and become available every 4 seconds.
#    The homing missiles get a target based on a few different factors,
#    then pretty much without fail will kill that target. I also added
#    Saucers which appear in the 2nd round, that shoot at the player
#    based on his current speed. Overall, I believe all the changes
#    make the game much more enjoyable. 
#
#    Estimated:  6.0 hrs
#    Actual:     4.0+ hrs - The base game took me 4.0 hours the rest
#                           of the added content took quite a bit longer
#      The hardest part was getting my homing missile to behave correctly
########################################################################


########################################################################
# The game
########################################################################
a.out: prj4.o transform.o gameObjects.o asteroids.o uiInteract.o uiDraw.o ai.o
	g++ -o a.out prj4.o transform.o gameObjects.o asteroids.o uiDraw.o uiInteract.o ai.o -lglut -lGLU

#######################################################################
# Seperately compiled files
#######################################################################
prj4.o: prj4.cpp asteroids.cpp asteroids.h gameObjects.cpp gameObjects.h
	g++ prj4.cpp -c

uiInteract.o: uiInteract.h uiInteract.cpp
	g++ uiInteract.cpp uiInteract.h -c

uiDraw.o: uiDraw.h uiDraw.cpp
	g++ uiDraw.cpp uiDraw.h -c

asteroids.o: asteroids.cpp asteroids.h gameObjects.h gameObjects.cpp
	g++ asteroids.cpp -c

ai.o: ai.cpp ai.h point.h gameObjects.h gameObjects.cpp
	g++ ai.cpp -c

gameObjects.o: gameObjects.cpp gameObjects.h transform.cpp transform.h point.h
	g++ gameObjects.cpp -c

transform.o: transform.cpp transform.h point.h
	g++ transform.cpp -c

#######################################################################
# Extra Stuff
#######################################################################
clean:
	rm *.o *.out