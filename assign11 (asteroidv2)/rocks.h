#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10



// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock
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
};


#endif /* rocks_h */
