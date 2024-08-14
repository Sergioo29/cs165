/*************************************************************************
* rocks.h
*************************************************************************/

#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SPIN 1
#define MEDIUM_ROCK_SPIN 4
#define SMALL_ROCK_SPIN 6

#define BIG_ROCK_MAX_SPEED     0.5
#define MEDIUM_ROCK_MAX_SPEED  1.0
#define SMALL_ROCK_MAX_SPEED   1.5

#define BIG_ROCK_HITS    4     // To break it
#define MEDIUM_ROCK_HITS 2

#include "flyingObject.h"

class Rock : public FlyingObject
{
protected:
  int rotation;
public:
  Rock(const Point & point)
  {
    alive = true;
    setPoint(point);
  }
  virtual void draw() = 0;
  virtual int hit() = 0;
  
};



class BigRock : public Rock
{
private:
  int lives; // Need more than 1 hit to break a big one
public:
  BigRock(const Point & point);
  
  virtual void draw();
  virtual int hit();
};



class MediumRock : public Rock
{
private:
  int lives;
public:
  MediumRock(const Point & point);
  
  virtual void draw();
  virtual int hit();
};


class SmallRock : public Rock
{
private:

public:
  SmallRock(const Point & point);
  
  virtual void draw();
  virtual int hit();
  virtual void kill();
};


#endif /* rocks_h */
