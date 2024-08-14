/*********************************************************************
 * File: game.cpp
 *********************************************************************/
// These are needed for the getClosestDistance function (not implemented)
//#include <limits>
//#include <algorithm>

#include <vector>

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

 /*********************************************
 * Constructor
 * Initializes the game
 *********************************************/
Game :: Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
   {
      // Set up the initial conditions of the game    
      Point initialShipPosition(0, -100);
      ship.setPoint(initialShipPosition);
      ship.setAmmo(AMMO);
      ship.setAngle(0);
      
      rock1 = createRock();
      rock1Shrink = 0;       // Logic 0= Big/Original, 1=Medium, 2=Small
      rock1piece = NULL;
      rock1pieceShrink = 0; 
      
      rock2 = createRock();
      rock2Shrink = 0;
      rock2piece = NULL;
      rock2pieceShrink = 0;
      
      rock3 = createRock();
      rock3Shrink = 0;
      rock3piece = NULL;
      rock3pieceShrink = 0;
      
      rock4 = createRock();
      rock4Shrink = 0;
      rock4piece = NULL;
      rock4pieceShrink = 0;
      
      rock5 = createRock();
      rock5Shrink = 0;
      rock5piece = NULL;
      rock5pieceShrink = 0;
      
      score = 0;
      time = 0.0;
      win = false; // Determine if all Asterois have been destroyed
   }

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (ship.isAlive() && ship.getAmmo() > 0 && win == false)
   {
      advanceRock();
      advanceBullets();
      ship.advance();
      if (!isOnScreen(ship.getPoint()))
         ship.setPoint(wrap(ship.getPoint()));  
    
      handleCollisions();
      shapeRock();
      cleanUpZombies();
      
      time += 0.02;
      
      if (rock1 == NULL && rock1piece == NULL && rock2 == NULL && 
          rock2piece == NULL && rock3 == NULL && rock3piece == NULL && 
          rock4 == NULL && rock4piece == NULL && rock5 == NULL && 
          rock5piece == NULL)
         win = true;
   }
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].advance();
         if (!isOnScreen(bullets[i].getPoint()))
            bullets[i].setPoint(wrap(bullets[i].getPoint()));
         if (bullets[i].getAdvanceCounter() >= BULLET_LIFE)
            bullets[i].kill();
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE ROCK
 *
 * 1. If there is a rock, and it's alive, advance it
 * 2. Check if the rock has gone of the screen, and if so, "wrap" it
 **************************************************************************/
void Game :: advanceRock()
{
   if (rock1 != NULL && rock1->isAlive()) // We have a rock, ensure it's alive
   {
      rock1->advance();                   // Move it       
      if (!isOnScreen(rock1->getPoint())) // Wrap it
            rock1->setPoint(wrap(rock1->getPoint()));
   }
   if (rock1piece != NULL && rock1piece->isAlive()) 
   {
      rock1piece->advance();                        
      if (!isOnScreen(rock1piece->getPoint()))
            rock1piece->setPoint(wrap(rock1piece->getPoint()));
   }
   
   if (rock2 != NULL && rock2->isAlive())
   {
      rock2->advance();      
      if (!isOnScreen(rock2->getPoint()))
         rock2->setPoint(wrap(rock2->getPoint()));
   }
   if (rock2piece != NULL && rock2piece->isAlive())
   {
      rock2piece->advance();      
      if (!isOnScreen(rock2piece->getPoint()))
         rock2piece->setPoint(wrap(rock2piece->getPoint()));
   }
   
   if (rock3 != NULL && rock3->isAlive())
   {
      rock3->advance();      
      if (!isOnScreen(rock3->getPoint()))
         rock3->setPoint(wrap(rock3->getPoint()));
   }
   if (rock3piece != NULL && rock3piece->isAlive())
   {
      rock3piece->advance();
      if (!isOnScreen(rock3piece->getPoint()))
         rock3piece->setPoint(wrap(rock3piece->getPoint()));
   }
   
   if (rock4 != NULL && rock4->isAlive())
   {
      rock4->advance();      
      if (!isOnScreen(rock4->getPoint()))
         rock4->setPoint(wrap(rock4->getPoint()));
   }
   if (rock4piece != NULL && rock4piece->isAlive())
   {
      rock4piece->advance();      
      if (!isOnScreen(rock4piece->getPoint()))
         rock4piece->setPoint(wrap(rock4piece->getPoint()));
   }
   
   if (rock5 != NULL && rock5->isAlive())
   {
      rock5->advance();      
      if (!isOnScreen(rock5->getPoint()))
         rock5->setPoint(wrap(rock5->getPoint()));
   }
   if (rock5piece != NULL && rock5piece->isAlive())
   {
      rock5piece->advance();
      if (!isOnScreen(rock5piece->getPoint()))
         rock5piece->setPoint(wrap(rock5piece->getPoint()));
   } 
}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create the initial asteroids at a random place
 **************************************************************************/
Rock* Game :: createRock()
{
   Point newPoint;
   newPoint.setX(random(-175, 175)); // Spawn at a random place
   newPoint.setY(random(-175, 175));
   
   Rock * newRock = new BigRock(newPoint);
   
   return newRock;
}

/**************************************************************************
 * GAME :: SHAPE ROCK
 * After being destroyed, check if the Asteroid can shrink
 **************************************************************************/
void Game :: shapeRock()
{   
   if (rock1Shrink == 1)
   {
      rock1 = new MediumRock(rock1->getPoint());
      rock1Shrink = 0;
   }
   if (rock1Shrink == 2)
   {
      rock1 = new SmallRock(rock1->getPoint());
      rock1Shrink = 0;
   }
   if (rock1pieceShrink == 2)
   {
      rock1piece = new SmallRock(rock1piece->getPoint());
      rock1pieceShrink = 0;
   }
   //********************************************
   if (rock2Shrink == 1)
   {
      rock2 = new MediumRock(rock2->getPoint());
      rock2Shrink = 0;
   }
   if (rock2Shrink == 2)
   {
      rock2 = new SmallRock(rock2->getPoint());
      rock2Shrink = 0;
   }
   if (rock2pieceShrink == 2)
   {
      rock2piece = new SmallRock(rock2piece->getPoint());
      rock2pieceShrink = 0;
   }
   //********************************************   
   if (rock3Shrink == 1)
   {
      rock3 = new MediumRock(rock3->getPoint());
      rock3Shrink = 0;
   }
   if (rock3Shrink == 2)
   {
      rock3 = new SmallRock(rock3->getPoint());
      rock3Shrink = 0;
   }
   if (rock3pieceShrink == 2)
   {
      rock3piece = new SmallRock(rock3piece->getPoint());
      rock3pieceShrink = 0;
   }
   //********************************************   
   if (rock4Shrink == 1)
   {
      rock4 = new MediumRock(rock4->getPoint());
      rock4Shrink = 0;
   }
   if (rock4Shrink == 2)
   {
      rock4 = new SmallRock(rock4->getPoint());
      rock4Shrink = 0;
   }
   if (rock4pieceShrink == 2)
   {
      rock4piece = new SmallRock(rock4piece->getPoint());
      rock4pieceShrink = 0;
   }
   //********************************************      
   if (rock5Shrink == 1)
   {
      rock5 = new MediumRock(rock5->getPoint());
      rock5Shrink = 0;
   }
   if (rock5Shrink == 2)
   {
      rock5 = new SmallRock(rock5->getPoint());
      rock5Shrink = 0;
   }
   if (rock5pieceShrink == 2)
   {
      rock5piece = new SmallRock(rock5piece->getPoint());
      rock5pieceShrink = 0;
   } 
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
 * GAME :: WRAP
 * If an object goes off screen, it spawns on the opposite side
 **************************************************************************/
Point Game :: wrap(const Point & point)
{
   Point newWrap;
   
   if (!point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
       || !point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT)
      newWrap.setX((point.getX() * (-1)));
   else
      newWrap.setX(point.getX());
    
   if(!point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT    
      || !point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT)
      newWrap.setY((point.getY() * (-1)));
   else
      newWrap.setY(point.getY());
   
   return newWrap;

}


/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between objects.
 **************************************************************************/
void Game :: handleCollisions()
{
   // Check for a hit, each living bullet, for each the five rock objects.
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // Check if the rock is at this point (in case it was hit)
         if (rock1 != NULL && rock1->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock1->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock1->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock1Shrink += rock1->hit();
               if (rock1Shrink == 1) // If it shrinks, create an piece
                  rock1piece = new MediumRock(rock1->getPoint());
               score += POINTS_PER_HIT;
               bullets[i].kill();        // The bullet is dead as well
            }
         }
         if (rock1piece != NULL && rock1piece->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock1piece->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock1piece->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock1pieceShrink += rock1piece->hit();
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
         
         if (rock2 != NULL && rock2->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock2->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock2->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock2Shrink += rock2->hit();
               if (rock2Shrink == 1)
                  rock2piece = new MediumRock(rock2->getPoint());
               score += POINTS_PER_HIT;
               bullets[i].kill();         
            }
         }
         if (rock2piece != NULL && rock2piece->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock2piece->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock2piece->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock2pieceShrink += rock2piece->hit();
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
         
         if (rock3 != NULL && rock3->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock3->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock3->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock3Shrink += rock3->hit();
               if (rock3Shrink == 1)
                  rock3piece = new MediumRock(rock3->getPoint());
               score += POINTS_PER_HIT;
               bullets[i].kill();         
            }
         }
         if (rock3piece != NULL && rock3piece->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock3piece->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock3piece->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock3pieceShrink += rock3piece->hit();
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
         
         if (rock4 != NULL && rock4->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock4->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock4->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock4Shrink += rock4->hit();
               if (rock4Shrink == 1)
                  rock4piece = new MediumRock(rock4->getPoint());
               score += POINTS_PER_HIT;
               bullets[i].kill();        
            }
         }
         if (rock4piece != NULL && rock4piece->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock4piece->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock4piece->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock4pieceShrink += rock4piece->hit();
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
         
         if (rock5 != NULL && rock5->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock5->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock5->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock5Shrink += rock5->hit();
               if (rock5Shrink == 1)
                  rock5piece = new MediumRock(rock5->getPoint());
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
         if (rock5piece != NULL && rock5piece->isAlive())
         {
            if (fabs(bullets[i].getPoint().getX() - rock5piece->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock5piece->getPoint().getY()) < CLOSE_ENOUGH)
            {  
               rock5pieceShrink += rock5piece->hit();
               score += POINTS_PER_HIT;
               bullets[i].kill();
            }
         }
      } 
   }
   
   // Handle ship collisions
   if (rock1 != NULL && rock1->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock1->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock1->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
   if (rock1piece != NULL && rock1piece->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock1piece->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock1piece->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
   
   if (rock2 != NULL && rock2->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock2->getPoint().getX()) < CLOSE_ENOUGH
         && fabs(ship.getPoint().getY() - rock2->getPoint().getY()) < CLOSE_ENOUGH)
         ship.kill();
   }
   if (rock2piece != NULL && rock2piece->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock2piece->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock2piece->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
   
   if (rock3 != NULL && rock3->isAlive()){
      if (fabs(ship.getPoint().getX() - rock3->getPoint().getX()) < CLOSE_ENOUGH
         && fabs(ship.getPoint().getY() - rock3->getPoint().getY()) < CLOSE_ENOUGH)
         ship.kill();
   }
   if (rock3piece != NULL && rock3piece->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock3piece->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock3piece->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
   
   if (rock4 != NULL && rock4->isAlive()){
      if (fabs(ship.getPoint().getX() - rock4->getPoint().getX()) < CLOSE_ENOUGH
         && fabs(ship.getPoint().getY() - rock4->getPoint().getY()) < CLOSE_ENOUGH)
         ship.kill(); 
   }
   if (rock4piece != NULL && rock4piece->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock4piece->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock4piece->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
   
   if (rock5 != NULL && rock5->isAlive()){
      if (fabs(ship.getPoint().getX() - rock5->getPoint().getX()) < CLOSE_ENOUGH
         && fabs(ship.getPoint().getY() - rock5->getPoint().getY()) < CLOSE_ENOUGH)
         ship.kill(); 
   }
   if (rock5piece != NULL && rock5piece->isAlive()) {
      if (fabs(ship.getPoint().getX() - rock5piece->getPoint().getX()) < CLOSE_ENOUGH
        && fabs(ship.getPoint().getY() - rock5piece->getPoint().getY()) < CLOSE_ENOUGH)
        ship.kill();
   }
}


/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rocks)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   if (rock1 != NULL && !rock1->isAlive())
   {
      delete rock1;  // the asteroid is dead, clean up the memory used by it
      rock1 = NULL;
   }
   if (rock1piece != NULL && !rock1piece->isAlive())
   {
      delete rock1piece;
      rock1piece = NULL;
   }
   
   if (rock2 != NULL && !rock2->isAlive())
   {
      delete rock2;
      rock2 = NULL;
   }
   if (rock2piece != NULL && !rock2piece->isAlive())
   {
      delete rock2piece;
      rock2piece = NULL;
   }
   
   if (rock3 != NULL && !rock3->isAlive())
   {
      delete rock3;
      rock3 = NULL;
   }
   if (rock3piece != NULL && !rock3piece->isAlive())
   {
      delete rock3piece;
      rock3piece = NULL;
   }
   
   if (rock4 != NULL && !rock4->isAlive())
   {
      delete rock4;
      rock4 = NULL;
   }
   if (rock4piece != NULL && !rock4piece->isAlive())
   {
      delete rock4piece;
      rock4piece = NULL;
   }
   
   if (rock5 != NULL && !rock5->isAlive())
   {
      delete rock5;
      rock5 = NULL;
   }
   if (rock5piece != NULL && !rock5piece->isAlive())
   {
      delete rock5piece;
      rock5piece = NULL;
   }
   
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())         // Look for dead bullets
   {
      Bullet bullet = *bulletIt;
      
      if (!bullet.isAlive())
         bulletIt = bullets.erase(bulletIt); // Remove from list and advance
      else
         bulletIt++;                         // Advance
   }
}


/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ship.isAlive() && ship.getAmmo() > 0 && win == false)
   {
      if (ui.isUp())
      {
         ship.turnUp();
         ship.moveUp();
      }
      
      if (ui.isDown())
      {
         ship.turnDown();
         ship.moveDown();
      }
      
      if (ui.isLeft())
      {
         ship.turnLeft();
         ship.moveLeft();
      }

      if (ui.isRight())
      {
         ship.turnRight();
         ship.moveRight();
      }  
        
      if (ui.isSpace())
      {
         if (ship.canShoot())
         {
            ship.useAmmo();
            Bullet newBullet;
            newBullet.fire(ship.getPoint(), ship.getAngle());
            bullets.push_back(newBullet);
         }
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   ship.draw();
   
   if (rock1 != NULL && rock1->isAlive())
      rock1->draw();
   if (rock1piece != NULL && rock1piece->isAlive())
      rock1piece->draw();
      
   if (rock2 != NULL && rock2->isAlive())
      rock2->draw();
   if (rock2piece != NULL && rock2piece->isAlive())
      rock2piece->draw();
      
   if (rock3 != NULL && rock3->isAlive())
      rock3->draw();
   if (rock3piece != NULL && rock3piece->isAlive())
      rock3piece->draw();
      
   if (rock4 != NULL && rock4->isAlive())
      rock4->draw();
   if (rock4piece != NULL && rock4piece->isAlive())
      rock4piece->draw();
      
   if (rock5 != NULL && rock5->isAlive())
      rock5->draw();
   if (rock5piece != NULL && rock5piece->isAlive())
      rock5piece->draw();

   // Draw the bullets
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
         bullets[i].draw();
   }
   
   //******************************************
   // Messages
   if (!ship.isAlive() || ship.getAmmo() <= 0)
      drawText(Point(), "G A M E   O V E R");
      
   if (win)
      drawText(Point(), "Y O U   W I N  ! !");

   Point ammoLocation;
   ammoLocation.setX(topLeft.getX() + 5);
   ammoLocation.setY(topLeft.getY() - 20);
   drawNumber(ammoLocation, ship.getAmmo());

   Point ammoLocationName;
   ammoLocationName.setX(topLeft.getX() + 5);
   ammoLocationName.setY(topLeft.getY() - 15);   
   drawText(ammoLocationName, "Ammo:");
   drawRect(ammoLocationName, 120, 35, 0);
   
   Point scoreLocation;
   if (score < 10)
      scoreLocation.setX(topLeft.getX() + 390);
   if (score >= 10)
      scoreLocation.setX(topLeft.getX() + 380);
   if (score >= 100)
      scoreLocation.setX(topLeft.getX() + 370);
   if (score >= 1000)
      scoreLocation.setX(topLeft.getX() + 360);
   if (score >= 10000)
      scoreLocation.setX(topLeft.getX() + 350);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);
   
   Point instructions;
   instructions.setX(bottomRight.getX() - 230); 
   instructions.setY(bottomRight.getY() + 25);
   if (time < 3.0 && ship.isAlive())
      drawText(instructions, "Destroy all the asteroids to win");
   if (time > 5.0 && time < 10.0 && ship.isAlive())
      drawText(instructions, "ARROWKEYS: move  SPACEBAR: shoot");
   if (time > 12.0 && time < 15.0 && ship.isAlive())
      drawText(instructions, "If you collide, BOOM ! got it?");
   if (time > 17.0 && time < 20.0 && ship.isAlive())
      drawText(instructions, "Running out of ammo is fatal");
   
}

/****************   END    ************************************/


// I left this function here because I like it
// But, we have a speed cap for the ship, so we don't need it

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

