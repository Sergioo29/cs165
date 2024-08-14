/*************************************************************
 * File: game.cpp
 * Author: Br. Burton and Sergio Henrique
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

// end-game condition values
#define MAX_TIME 60.0  //avoid setting this to less than 30.0
#define MIN_SCORE -11
#define MAX_SCORE 30


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // DONE: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // DONE: Check to see if there is currently a bird allocated
   //       and if so, delete it.
   if (bird != NULL)
   {
     delete bird;
     bird = NULL;
   }

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (score > MIN_SCORE && score < MAX_SCORE && time <= MAX_TIME)
   {
   
   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
   
   time += 0.02;
   
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
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      
      // "resurrect" it will some random chance
      if (random(0, 20) == 0)
      {
         // create a new bird
         bird = createBird();
      }
   }
   else
   {
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         bird->advance();
         
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
   Bird* newBird = NULL;

   // DONE: Fill this in
   Point newPoint;
   newPoint.setX(topLeft.getX());
   newPoint.setY(random(bottomRight.getY(), topLeft.getY()));
   
   int birdType = random(0, 3);
   
   if (birdType == 0)
     newBird = new NormalBird(newPoint);
   
   else  if (birdType == 1)
     newBird = new ToughBird(newPoint);
     
   else
     newBird = new SacredBird(newPoint);
   
   
   return newBird;
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
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // DONE: Clean up the memory used by the bird
      delete bird;
      bird = NULL;
   
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
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the bird

   // DONE: Check if you have a valid bird and if it's alive
   // then call it's draw method
   if (bird != NULL && bird->isAlive() == true)
     bird->draw();
  

   // draw the rifle
   rifle.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   // Put the score on the screen   
   Point scoreLocationName;
   scoreLocationName.setX(topLeft.getX() + 5);
   scoreLocationName.setY(topLeft.getY() - 15);   
   drawText(scoreLocationName, "Score:");   
   
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 10);
   scoreLocation.setY(topLeft.getY() - 20);
   drawNumber(scoreLocation, score);
   
   
   // Put the time on the screen
   Point timeName;
   timeName.setX(topLeft.getX() + 367);
   timeName.setY(topLeft.getY() - 15);
   if (time >= 23.0)
     drawText(timeName, "Time:");
   
   Point timeLocation;
   timeLocation.setX(topLeft.getX() + 372);
   timeLocation.setY(topLeft.getY() - 20);
   if (time >= 23.0)
     drawNumber(timeLocation, time);
   
   
   // Put commands on the screen
   Point commands1;
   commands1.setX(topLeft.getX() + 290);
   commands1.setY(topLeft.getY() - 15);   
   if (time >= 0.0 && time < 5.0)
     drawText(commands1, "ARROWKEY: Aim");
   
   Point commands2;
   commands2.setX(topLeft.getX() + 290);
   commands2.setY(topLeft.getY() - 30);   
   if (time >= 0.0 && time < 5.0)
     drawText(commands2, "SPACEBAR: Shoot");
   
   
   // Put instructions on the screen
   Point instructions;
   instructions.setX(topLeft.getX() + 100);
   instructions.setY(topLeft.getY() - 15);
   
   Point instructions2;
   instructions2.setX(topLeft.getX() + 247);
   instructions2.setY(topLeft.getY() - 5);
   
   if (time >= 0.0 && time < 3.0)
     drawText(instructions, "Hit the targets that appear");
   if (time >= 5.0 && time < 8.0 || time >= 30.0 && time < MAX_TIME)
   {
     drawText(instructions, "To win, reach a score of:");
     drawNumber(instructions2, MAX_SCORE);
   }
   if (time >= 10.0 && time < 13.0)
     drawText(instructions, "White targets needs three hits");
   if (time >= 13.0 && time < 16.0)
     drawText(instructions, "Destroying them grants bonus points");
   if (time >= 18.0 && time < 21.0)
     drawText(instructions, "AVOID hitting the red stars");
   if (time >= 23.0 && time < 27.0)
   {
     drawText(instructions, "You have ultil time reach:");
     drawNumber(instructions2, MAX_TIME);
   }
   
   
   
  // End-game condition messages
   if (score <= MIN_SCORE)
   {
     Point SacredKiller;
     SacredKiller.setX(topLeft.getX() + 100);
     SacredKiller.setY(topLeft.getY() - 100);   
     drawText(SacredKiller, "FAIL!! You have shot too many red stars...");
   }
   
   if (time >= MAX_TIME)
   {
     Point OutofTime;
     OutofTime.setX(topLeft.getX() + 100);
     OutofTime.setY(topLeft.getY() - 100);   
     drawText(OutofTime, "FAIL!! Time is up...");
   }
   
   if (score >= MAX_SCORE)
   {
     Point OutofTime;
     OutofTime.setX(topLeft.getX() + 100);
     OutofTime.setY(topLeft.getY() - 100);   
     drawText(OutofTime, "Y O U   W I N !!");
   }
   
}

