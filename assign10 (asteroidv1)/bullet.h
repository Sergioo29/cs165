#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"

//static const float BULLET_SPEED = 10.0;

class Bullet : public FlyingObject
{
private:

public:
  Bullet() { alive = true; }
  
  virtual void draw();
  void fire (const Point & point, float angle);

};



#endif /* bullet_h */
