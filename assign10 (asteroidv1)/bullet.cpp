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
  
  velocity.setDx(-cos(M_PI / 180.0 * angle) * BULLET_SPEED);
  velocity.setDy(sin(M_PI / 180.0 * angle) * BULLET_SPEED);
 
  alive = true;   
}
