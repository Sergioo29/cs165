###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Sergio Henrique
# Summary:
#     This program runs a Moon Lander game.
#     It shows simple instructions in the screen and the fuel amount.
#     If the fuel empties, the plater can't move the lander.
#     If the player move to the sides of the screen, too much high, or touch
#     the withe rocks, he loses
#     The player can't land the ship if it is too fast.
# Above and Beyond
#     I added the instructions in the screen and added the word "Fuel" above
#     the fuel number. I also put the lander quite above the screen and
#     turned down the gravity a little, to give the player a reaction window.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o:	lander.h lander.cpp point.h
				g++	-c	lander.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
