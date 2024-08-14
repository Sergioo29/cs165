
#include "rocks.h"
#include "uiDraw.h"

BigRock :: BigRock(const Point & point) : Rock(point)
{
  rotation = 0;

  float dx = random(-0.2, 0.2);
  float dy = random(-0.2, 0.2);
  if (dx == 0) // Assert velocity is not 0
    dx = 0.2;
  if (dy == 0)
    dy = 0.2;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void BigRock :: draw()
{
  rotation+=1;
  if(alive)
    drawLargeAsteroid(point, rotation);

}


int BigRock :: hit()
{
  kill();
  return 0;
}

//-----------------------------------------------------------//

MediumRock :: MediumRock(const Point & point) : Rock(point)
{
  lives = 0;
  rotation = 0;
    
  float dx = random(-0.3, 0.3);
  float dy = random(-0.3, 0.3);
  
  if (dx == 0) // Assert velocity is not 0
    dx = 0.3;
  if (dy == 0)
    dy = 0.3;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void MediumRock :: draw()
{
  rotation-=3;
  if(alive)
    drawMediumAsteroid(point, rotation);
}


int MediumRock :: hit()
{
  if (lives <= 0)
  {
    kill();
    return 0;
  }
  else
  {
    lives -= 1;
    return 0;
  }
}


//------------------------------------------------------------//


SmallRock :: SmallRock(const Point & point) : Rock(point)
{
  rotation = 0;

  float dx = random(-0.6, 0.6);
  float dy = random(-0.6, 0.6);
   if (dx == 0) // Assert velocity is not 0
      dx = 0.6;
   if (dy == 0)
      dy = 0.6;
  
  Velocity newVelocity;
  newVelocity.setDx(dx);
  newVelocity.setDy(dy);
  
  setVelocity(newVelocity);
}


void SmallRock :: draw()
{
  rotation+=6;
  if(alive)
    drawSmallAsteroid(point, rotation);
}


int SmallRock :: hit()
{
  kill();
  return 0;
}


