/*************************************************************************
* ship.cpp
*************************************************************************/

#include "ship.h"
#include "point.h"
#include "uiDraw.h"

#include <cassert>

bool Ship :: canShoot() const
{
  return (isAlive() && ammo > 0);
}

// **********   Ship Movement   ************

void Ship :: moveLeft()
{
   if (velocity.getDx() > -SPEED_CAP){
      float speed = velocity.getDx() - SPEED_UP_AMOUNT;     
      velocity.setDx(speed);
   }   
}

void Ship :: turnLeft()
{
   /*if (angle == 0.0)
      angle = 5.0;
   if (angle < ANGLE_LEFT)       This is for a smooth turn, but it's bugging
      angle += SHIP_MOVE_AMOUNT;
   if (angle > ANGLE_LEFT)
      angle -= SHIP_MOVE_AMOUNT;
   if (angle > 60.0 && angle < 120.0)*/
      angle = ANGLE_LEFT;
}



void Ship :: moveRight()
{
   if (velocity.getDx() < SPEED_CAP){
      float speed = velocity.getDx() + SPEED_UP_AMOUNT;
      velocity.setDx(speed);
   }
}

void Ship :: turnRight()
{
      angle = ANGLE_RIGHT;
}



void Ship :: moveUp()
{
   if (velocity.getDy() < SPEED_CAP){
      float speed = velocity.getDy() + SPEED_UP_AMOUNT; 
      velocity.setDy(speed);
   }
}

void Ship :: turnUp()
{
      angle = ANGLE_UP;
}


void Ship :: moveDown()
{
   if (velocity.getDy() > -SPEED_CAP){
      float speed = velocity.getDy() - SPEED_UP_AMOUNT; 
      velocity.setDy(speed);
   }
}

void Ship :: turnDown()
{
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

void Ship :: kill()
{
  drawCircle(point, 15); // The "explosion" effect
  drawCircle(point, 20);
  drawCircle(point, 25);
  drawCircle(point, 30);

  alive = false;
}

