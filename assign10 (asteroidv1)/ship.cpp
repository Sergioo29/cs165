
#include "ship.h"
#include "uiDraw.h"

bool Ship :: canThrust()
{
  return (isAlive() && fuel > 0);
}

void Ship :: applyThrustLeft()
{
  if (canThrust())
  {
     float speed = velocity.getDx() + 0.1;
     velocity.setDx(speed);
     fuel -= 0;
  }

}

void Ship :: applyThrustRight()
{
  if (canThrust())
  {
     float speed = velocity.getDx() - 0.1;
     velocity.setDx(speed);
     fuel -= 0;
  }
     
}


void Ship :: applyThrustUp()
{
if (canThrust())
  {
     float speed = velocity.getDy() - 0.1; 
     velocity.setDy(speed);
     fuel -= 0;
  }
}


void Ship :: applyThrustBottom()
{
  if (canThrust())
  {
     float speed = velocity.getDy() + 0.1; 
     velocity.setDy(speed);
     fuel -= 0;
  }
}


void Ship :: advance()
{
  float dx = velocity.getDx();
  float dy = velocity.getDy();  
  point.addX(dx);
  point.addY(dy);
}


void Ship :: draw() const
{
  if (isAlive())
    drawShip(point, 0);
}

