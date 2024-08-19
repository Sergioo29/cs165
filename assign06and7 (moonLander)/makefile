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

# Compiler and linker
CXX = mingw32-g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lfreeglut -lglu32 -lopengl32

# Source files
SRCS = driver.cpp ground.cpp game.cpp uiInteract.cpp uiDraw.cpp point.cpp lander.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = moonlander.exe

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	del /Q $(OBJS) $(EXEC)

# Rebuild the project
rebuild: clean all

