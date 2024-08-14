###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Alvey, CS165
# Author:
#     Sergio Henrique
# Summary:
#     An Asteroid Game program.
#     You can move the ship with arrow keys. Each key tap turns the ship
#     into that direction straight, hold the key moves the ship (hold more
#     to speed up, up to a cap).
#     Spacebar shoots the ship gun, the project only travels a 40 frames
#     distance, so it vanishes into the vast space. You have limited ammo,
#     running out of ammo result in a Game Over, so shoot wisely.
#     The asteroids break apart when receiving enough hits (more than one, yes).
#     Colliding with an asteroid explodes the ship and is Game Over.
#     To win, the player needs to destroy all the asterois, all of them, at all.
#     We have a score system, just to assimilate with the original old games.

# Above and Beyond:
#     * Ship "explosion" effect
#     * Speed cap for the ship
#     * Limited ammo
#     * Asteroid "hit" effect
#     * Asteroid needs more hits to break
#     * Instructions entering and leaving the screen
#     * Time system (not shown on screen, but it can be used on other purposes)
#     * Score system (no purpose, honest)

###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out asteroids.tar *.o
