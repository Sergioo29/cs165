/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class methods.
 *********************************************************************/
// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include <vector>

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5
#define MAX_SCORE 30


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (ship.isAlive())
   {
      ship.advance();
      advanceRock();
    //advancebullets
    
      handleCollisions();
      cleanUpZombies();

      if (!isOnScreen(ship.getPoint()))
         ship.setAlive(false);
         
     /*if (!ground.isAboveGround(ship.getPoint())) 
         ship.setAlive(false); */              // CHECK FOR ASTEROID CRASH
   }
}


/**************************************************************************
 * GAME :: ADVANCE ROCK
 *
 * 1. If there is no rock, create one with some probability
 * 2. If there is a rock, and it's alive, advance it
 * 3. Check if the rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceRock()
{
   if (rock1 == NULL)
      rock1 = createRock();
   if (rock2 == NULL)
      rock2 = createRock();
   if (rock3 == NULL)
      rock3 = createRock();
   if (rock4 == NULL)
      rock4 = createRock();
   if (rock5 == NULL)
      rock5 = createRock();
   else
   {
      if (rock1->isAlive()) // we have a asteroid, make sure it's alive
      {
         rock1->advance();  // move it       
         if (!isOnScreen(rock1->getPoint()))//asteroid has gone off the screen
            rock1->kill();
      }
      if (rock2->isAlive())
      {
         rock2->advance();      
         if (!isOnScreen(rock2->getPoint()))
            rock2->kill();
      }
      if (rock3->isAlive())
      {
         rock3->advance();      
         if (!isOnScreen(rock3->getPoint()))
            rock3->kill();
      }
      if (rock4->isAlive())
      {
         rock4->advance();      
         if (!isOnScreen(rock4->getPoint()))
            rock4->kill();
      }
      if (rock5->isAlive())
      {
         rock5->advance();      
         if (!isOnScreen(rock5->getPoint()))
            rock5->kill();
      }   
   }
}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create an asteroid of a random type according to the rules of the game.
 **************************************************************************/
Rock* Game :: createRock()
{
   Rock * newRock = NULL;

   Point newPoint;
   newPoint.setX(random(-175, 175)); // Spawn at random place
   newPoint.setY(random(-175, 175));
   
   int rockType = random(0, 3);  // Randow asteroid, need to change!!
   
   if (rockType == 0)
     newRock = new BigRock(newPoint);
   else  if (rockType == 1)
     newRock = new MediumRock(newPoint);
   else
     newRock = new SmallRock(newPoint);
   
   return newRock;
}


/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}


/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // check if the bird is at this point (in case it was hit)
         if (rock1 != NULL && rock1->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock1->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock1->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               /*int points =*/ rock1->hit();  // hit the asteroid
               //score += points;             
               bullets[i].kill();         // the bullet is dead as well
            }
         }
      } 
   }
}


/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead asteroid
   if (rock1 != NULL && !rock1->isAlive())
   {
      // the asteroid is dead, clean up the memory used by it
      delete rock1;
      rock1 = NULL;
   }
   if (rock2 != NULL && !rock2->isAlive())
   {
      delete rock2;
      rock2 = NULL;
   }
   if (rock3 != NULL && !rock3->isAlive())
   {
      delete rock3;
      rock3 = NULL;
   }
   if (rock4 != NULL && !rock4->isAlive())
   {
      delete rock4;
      rock4 = NULL;
   }
   if (rock5 != NULL && !rock5->isAlive())
   {
      delete rock5;
      rock5 = NULL;
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         //...
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
         bulletIt++; // advance
   }
}


/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ship.isAlive())
   {
      if (ui.isUp())
         ship.applyThrustUp();

      if (ui.isDown())
         ship.applyThrustBottom();

      if (ui.isLeft())
         ship.applyThrustLeft();

      if (ui.isRight())
         ship.applyThrustRight();
         
        // Spacebar to shoot later
      /*if (ui.isSpace())
      {
         Bullet newBullet;
         newBullet.fire(rifle.getPoint(), rifle.getAngle());
         bullets.push_back(newBullet);
      }*/
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   ship.draw();
   
   if (rock1 != NULL && rock1->isAlive() == true)
      rock1->draw();
   if (rock2 != NULL && rock2->isAlive() == true)
      rock2->draw();
   if (rock3 != NULL && rock3->isAlive() == true)
      rock3->draw();
   if (rock4 != NULL && rock4->isAlive() == true)
      rock4->draw();
   if (rock5 != NULL && rock5->isAlive() == true)
      rock5->draw();

// draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   //******************************************
   // Messages
   if (!ship.isAlive())
      drawText(Point(), "G A M E   O V E R");

   // IF WANNA USE FLAMES
   if (ship.canThrust())
      drawLanderFlames(ship.getPoint(), ui.isDown(), false, false);

   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 20);
   drawNumber(fuelLocation, ship.getFuel());

   Point fuelLocationName;
   fuelLocationName.setX(topLeft.getX() + 5); // Change it to bullets later
   fuelLocationName.setY(topLeft.getY() - 15);   
   drawText(fuelLocationName, "Energy:");
   
   Point instructions;
   instructions.setX(topLeft.getX() + 238); // Try to change to topRight
   instructions.setY(topLeft.getY() - 15);   
   drawText(instructions, "Destroy the asteroids !!");
   
   Point instructions2;
   instructions2.setX(topLeft.getX() + 238); // Same
   instructions2.setY(topLeft.getY() - 30);   
   drawText(instructions2, "Use ARROW KEYS to move");
   
}


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/

