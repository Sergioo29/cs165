/*********************************************************************
 * game.h
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

#define AMMO             100

#define POINTS_PER_HIT   10

#define CLOSE_ENOUGH     15

class Game
{

private:
   Point topLeft;
   Point bottomRight;
   
   Ship ship;
   std::vector<Bullet> bullets;
   
   Rock * rock1;
   short rock1Shrink;
   Rock * rock1piece;
   short rock1pieceShrink;
   
   Rock * rock2;
   short rock2Shrink;
   Rock * rock2piece;
   short rock2pieceShrink;
   
   Rock * rock3;
   short rock3Shrink;
   Rock * rock3piece;
   short rock3pieceShrink;
   
   Rock * rock4;
   short rock4Shrink;
   Rock * rock4piece;
   short rock4pieceShrink; 
  
   Rock * rock5;
   short rock5Shrink;
   Rock * rock5piece;
   short rock5pieceShrink;
   
   int score;
   double time;
   bool win;

   /*************************************
    * Private methods
    *************************************/
   bool isOnScreen(const Point & point);
   Point wrap(const Point & point);
   
   void advanceBullets();
   void advanceRock();
   Rock* createRock();
   void shapeRock();
   
   void handleCollisions();
   void cleanUpZombies();


public:
   
   Game(Point tl, Point br);
   
   void handleInput(const Interface & ui);
   
   void advance();
   
   void draw(const Interface & ui);
   
};


#endif /* GAME_H */
