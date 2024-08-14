/*****************************************************************************
File: bullet.h
Author: Sergio Henrique
*****************************************************************************/
#ifndef BULLET_H
#define BULLET_H
#include "flyingObject.h"

static const float BULLET_SPEED = 10.0;

class Bullet : public FlyingObject
{
private:

public:
  Bullet()
  {
    alive = true;
  }
  
  virtual void draw();
  void fire (const Point & point, float angle);

};


#endif
