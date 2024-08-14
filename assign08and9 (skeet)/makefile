###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Sergio Henrique
# Summary:
#     This is a Skeet game progam. You can aim and shoot on the "birds"
#     from the bottom-right side of the screen. The commands, goals,
#     tips and time are shown on the screen.
#
# Above and Beyond:
#      Added some text: The word "score" to represent the given score code.
#                       The commands on the top right side (temporary).
#                       Some guides and instructions on the top middle (temp.)
#                       The time (seconds) shown after some time and fixed.
#      Added the time system, each loop increments the time variable.
#      Added win/lose game conditions that can be quite easilly changed
#       by the game header within the define lines.
#       These end-game conditions include: Goal score, maximum time and
#       minimum score (so the player can't kill many sacred birds).
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o flyingObject.o velocity.o birds.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o flyingObject.o velocity.o birds.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
flyingObject.o: flyingObject.h flyingObject.cpp point.h
	g++ -c flyingObject.cpp
	
bullet.o: bullet.h bullet.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

birds.o: birds.h birds.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c birds.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
