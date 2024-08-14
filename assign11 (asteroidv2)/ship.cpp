
#include "ship.h"
#include "point.h"
#include "uiDraw.h"

#include <cassert>

bool Ship :: canShoot()
{
  return (isAlive() && ammo > 0);
}

// **********   Ship Movement   ************

void Ship :: applyThrustLeft()
{
     float speed = velocity.getDx() - THRUST_AMOUNT;
     velocity.setDx(speed);   
}

void Ship :: moveLeft()
{
   /*if (angle == 0.0)
      angle = 5.0;
   if (angle < ANGLE_LEFT)
      angle += SHIP_MOVE_AMOUNT;
   if (angle > ANGLE_LEFT)
      angle -= SHIP_MOVE_AMOUNT;
   if (angle > 60.0 && angle < 120.0)*/
      angle = ANGLE_LEFT;
}



void Ship :: applyThrustRight()
{
     float speed = velocity.getDx() + THRUST_AMOUNT;
     velocity.setDx(speed);
}

void Ship :: moveRight()
{
   /*if (angle == 0.0)
      angle = 355.0;
   if (angle < ANGLE_RIGHT)
      angle += SHIP_MOVE_AMOUNT;
   if (angle > ANGLE_RIGHT)
      angle -= SHIP_MOVE_AMOUNT;
   if (angle > 140.0 && angle < 200.0)*/
      angle = ANGLE_RIGHT;
}



void Ship :: applyThrustUp()
{
     float speed = velocity.getDy() + THRUST_AMOUNT; 
     velocity.setDy(speed);
}

void Ship :: moveUp()
{
   /*if (angle > 180.1)
      angle += SHIP_MOVE_AMOUNT;
   else
      angle -= SHIP_MOVE_AMOUNT;
   if (angle > 340 || angle < 20)*/
      angle = ANGLE_UP;
}


void Ship :: applyThrustDown()
{
     float speed = velocity.getDy() - THRUST_AMOUNT; 
     velocity.setDy(speed);
}

void Ship :: moveDown()
{
   /*if (angle < ANGLE_DOWN)
      angle += SHIP_MOVE_AMOUNT;
   if (angle > ANGLE_DOWN)
      angle -= SHIP_MOVE_AMOUNT;
   if (angle > 160.0 && angle < 200.0)*/
      angle = ANGLE_DOWN;
}

//**********  Movement and drawing ***************

void Ship :: advance()
{
  float dx = velocity.getDx();
  float dy = velocity.getDy();  
  point.addX(dx);
  point.addY(dy);
}


void Ship :: draw() const
{
  assert(angle >= ANGLE_MIN);
  assert(angle <= ANGLE_MAX);
  if (isAlive())
    drawShip(point, angle);
}

