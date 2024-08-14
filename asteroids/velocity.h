/*************************************************************************
* velocity.h
*************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"

class Velocity
{
private:
  float dx;
  float dy;

public:
  Velocity()
  {
    dx = 0.0;
    dy = 0.0;
  }
  Velocity(float dx, float dy);
  float getDx() const { return dx; }
  float getDy() const { return dy; }

  void setDx(float dx) { this->dx = dx; }
  void setDy(float dy) { this->dy = dy; }
  
  void add(const Velocity & other);
  void advancePoint(Point & point);

};

#endif /* velocity_h */
