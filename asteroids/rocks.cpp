/*************************************************************************
* rocks.cpp
*************************************************************************/

#include "rocks.h"
#include "uiDraw.h"


/******************************************************************
* BIG ASTEROID
*******************************************************************/
BigRock :: BigRock(const Point & point) : Rock(point)
{
  lives = BIG_ROCK_HITS;
  rotation = 0;

  float dx = random(-BIG_ROCK_MAX_SPEED, BIG_ROCK_MAX_SPEED);
  float dy = random(-BIG_ROCK_MAX_SPEED, BIG_ROCK_MAX_SPEED);
  if (dx == 0.0)                  // Assert speed is not 0
    dx = BIG_ROCK_MAX_SPEED;
  if (dy == 0.0)
    dy = BIG_ROCK_MAX_SPEED;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void BigRock :: draw()
{
  rotation+= BIG_ROCK_SPIN;
  if(alive)
    drawLargeAsteroid(point, rotation);

}


int BigRock :: hit()
{
  if (lives <= 0)
  {
    kill();
    return 1; // For the asteroid to shrink
  }
  else
  {
    lives -= 1;
    
    // An visual effect to show the player the "damage" dealt
    rotation-= (BIG_ROCK_SPIN + 10); 
    return 0;  // Return 0 for the asteroid to remain on its size
  }
}


/**********************************************************
* MEDIUM ASTEROID
***********************************************************/
MediumRock :: MediumRock(const Point & point) : Rock(point)
{
  lives = MEDIUM_ROCK_HITS;
  rotation = 0;
    
  float dx = random(-MEDIUM_ROCK_MAX_SPEED, MEDIUM_ROCK_MAX_SPEED);
  float dy = random(-MEDIUM_ROCK_MAX_SPEED, MEDIUM_ROCK_MAX_SPEED);
  
  if (dx > -(MEDIUM_ROCK_MAX_SPEED - 0.4) && dx < (MEDIUM_ROCK_MAX_SPEED - 0.4))
    dx = MEDIUM_ROCK_MAX_SPEED;
  if (dy > -(MEDIUM_ROCK_MAX_SPEED -0.4) && dy < (MEDIUM_ROCK_MAX_SPEED -0.4))
    dy = MEDIUM_ROCK_MAX_SPEED;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void MediumRock :: draw()
{
  rotation-= MEDIUM_ROCK_SPIN;
  if(alive)
    drawMediumAsteroid(point, rotation);
}


int MediumRock :: hit()
{
  if (lives <= 0)
  {
    kill();
    return 2;
  }
  else
  {
    lives -= 1;
    rotation+= (MEDIUM_ROCK_SPIN + 20);
    return 0;
  }
}


/************************************************
* SMALL ASTEROID
*************************************************/
SmallRock :: SmallRock(const Point & point) : Rock(point)
{
  rotation = 0;

  float dx = random(-SMALL_ROCK_MAX_SPEED, SMALL_ROCK_MAX_SPEED);
  float dy = random(-SMALL_ROCK_MAX_SPEED, SMALL_ROCK_MAX_SPEED);
   if (dx > -(SMALL_ROCK_MAX_SPEED - 0.3) && dx < (SMALL_ROCK_MAX_SPEED - 0.3))
      dx = SMALL_ROCK_MAX_SPEED;
   if (dy > -(SMALL_ROCK_MAX_SPEED - 0.3) && dy < (SMALL_ROCK_MAX_SPEED - 0.3))
      dy = SMALL_ROCK_MAX_SPEED;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void SmallRock :: draw()
{
  rotation+= SMALL_ROCK_SPIN;
  if(alive)
    drawSmallAsteroid(point, rotation);
}


int SmallRock :: hit()
{
  kill();
  return 0;
}

void SmallRock :: kill()
{
  drawCircle(point, 15); // An "explosion" effect
  drawCircle(point, 20);
  drawCircle(point, 25);
  drawCircle(point, 30);

  alive = false;
}

