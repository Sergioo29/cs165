/*********************************************************************
 * File: bullet.cpp
 *********************************************************************/
#include "bullet.h"
#include "uiDraw.h"

void Bullet :: draw()
{
  if(alive)
  {
    drawDot(point);
  }
}

void Bullet :: fire(const Point & point, float angle)
{
  this->point = point;
  
  velocity.setDx(-sin(M_PI / 180.0 * angle) * BULLET_SPEED);
  velocity.setDy(cos(M_PI / 180.0 * angle) * BULLET_SPEED);
 
  alive = true;   
}

void Bullet :: advance()
{
  advanceCounter += 1;
  
  float dx = velocity.getDx();
  float dy = velocity.getDy();  
  
  point.addX(dx);
  point.addY(dy);
  
}

