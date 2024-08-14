/***********************************************************************
 * Header File:
 *    Velocity header.
 * Author:
 *    Sergio Henrique
 * Summary:
 *    This is the velocity header.
 ************************************************************************/
#ifndef velocity_h
#define velocity_h

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


#endif
