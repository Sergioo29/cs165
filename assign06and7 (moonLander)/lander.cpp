/*****************************************************
 * File: lander.cpp
 * Author: Sergio Henrique
 *
 * Description: This file contains the lander class bodies.
 ******************************************************/
#include "lander.h"
#include "uiDraw.h"

void Lander :: applyGravity (float amount)
{
  float gravity = velocity.getDy() - amount;
  velocity.setDy(gravity);
}

bool Lander :: canThrust()
{
  return (isAlive() && !isLanded() && fuel > 0);
}

void Lander :: applyThrustLeft()
{
  if (canThrust())
  {
     float speed = velocity.getDx() + 0.1;
     velocity.setDx(speed);
     fuel -= 1;
  }

}

void Lander :: applyThrustRight()
{
  if (canThrust())
  {
     float speed = velocity.getDx() - 0.1;
     velocity.setDx(speed);
     fuel -= 1;
  }
     
}

void Lander :: applyThrustBottom()
{
  if (canThrust())
  {
     float speed = velocity.getDy() + 0.15; 
     velocity.setDy(speed);
     fuel -= 2;
  }
}

void Lander :: advance()
{
  float dx = velocity.getDx();
  float dy = velocity.getDy();  
  point.addX(dx);
  point.addY(dy);
}

void Lander :: draw() const
{
  if (isAlive())
    drawLander(point);
}
