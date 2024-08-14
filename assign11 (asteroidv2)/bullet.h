#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"

class Bullet : public FlyingObject
{
private:
  short advanceCounter;
  
public:
  Bullet() 
  {
     alive = true;
     advanceCounter = 0;
  }
  
  
  virtual void draw();
  void fire (const Point & point, float angle);
  
  int getAdvanceCounter() { return advanceCounter; }
  virtual void advance();

};


#endif /* bullet_h */
