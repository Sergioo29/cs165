/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"

#define FUEL        500
#define MIN_SPEED   3.0
#define CLOSE_ENOUGH 15

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{

private:
   
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   Ship ship;
   Rock * rock1;
   Rock * rock2;
   Rock * rock3;
   Rock * rock4;
   Rock * rock5;
   
   int score;

   std::vector<Bullet> bullets;

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   Rock* createRock();
   
   void handleCollisions();
   void cleanUpZombies();
 
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
   {
      // Set up the initial conditions of the game
      ship.setFuel(FUEL);
      Point initialShipPosition(0, 0);
      ship.setPoint(initialShipPosition);
      rock1 = NULL;
      rock2 = NULL;
      rock3 = NULL;
      rock4 = NULL;
      rock5 = NULL;
      // score = 0; In case which score is implemented
   }
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
};


#endif /* GAME_H */
