/*****************************************************************************
File: birds.cpp
Author: Sergio Henrique
*****************************************************************************/
#include "birds.h"
#include "uiDraw.h"

NormalBird :: NormalBird(const Point & point) : Bird(point)
{
  float dx = random(3, 6);
  float dy = random(0, 4);
  
  if (point.getY() > 0)
    dy *= -1;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void NormalBird :: draw()
{
  if(alive)
    drawCircle(point, BIRD_RADIUS);
}


int NormalBird :: hit()
{
  kill();
  return POINTS_NORMAL_BIRD;
}

//-----------------------------------------------------------//

ToughBird :: ToughBird(const Point & point) : Bird(point)
{
  lives = TOUGH_BIRD_TOUGHNESS;
  
  float dx = random(3, 6);
  float dy = random(0, 4);
  
  if (point.getY() > 0)
    dy *= -1;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void ToughBird :: draw()
{
  if(alive)
    drawToughBird(point, BIRD_RADIUS, lives);
}


int ToughBird :: hit()
{
  if (lives <= 0)
  {
    kill();
    return POINTS_TOUGH_BIRD_KILL;
  }
  else
  {
    lives -= 1;
    return POINTS_TOUGH_BIRD_HIT;
  }
}


//------------------------------------------------------------//


SacredBird :: SacredBird(const Point & point) : Bird(point)
{
  float dx = random(3, 6);
  float dy = random(0, 4);
  
  if (point.getY() > 0)
    dy *= -1;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void SacredBird :: draw()
{
  if(alive)
    drawSacredBird(point, BIRD_RADIUS);
}


int SacredBird :: hit()
{
  kill();
  return POINTS_SACRED_BIRD;
}





