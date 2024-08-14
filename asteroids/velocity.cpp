/*************************************************************************
* velocity.cpp
*************************************************************************/

#include "velocity.h"
#include "point.h"

Velocity :: Velocity(float dx, float dy)
{
  setDx(dx);
  setDy(dy);
}

void Velocity::add(const Velocity & other)
{
   dx += other.dx;
   dy += other.dy;
}

void Velocity::advancePoint(Point & point)
{
   point.addX(dx);
   point.addY(dy);
}
