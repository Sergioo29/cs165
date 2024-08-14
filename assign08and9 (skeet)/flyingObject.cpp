/*****************************************************
 * File: flyingObject.cpp
 * Author: Sergio Henrique
 ******************************************************/
#include "flyingObject.h"

void FlyingObject :: advance()
{
  float dx = velocity.getDx();
  float dy = velocity.getDy();  
  point.addX(dx);
  point.addY(dy);
}

