/*****************************************************************************
File: birds.h
Author: Sergio Henrique
*****************************************************************************/
#ifndef BIRDS_H
#define BIRDS_H

#include "flyingObject.h"

#define BIRD_RADIUS 15

#define POINTS_NORMAL_BIRD 1
#define POINTS_SACRED_BIRD -10

#define POINTS_TOUGH_BIRD_HIT 1
#define POINTS_TOUGH_BIRD_KILL 3
#define TOUGH_BIRD_TOUGHNESS 3


class Bird : public FlyingObject
{
private:
  
public:
  Bird(const Point & point)
  {
    alive = true;
    setPoint(point);
  }
  virtual void draw() = 0;
  virtual int hit() = 0;
  
};



class NormalBird : public Bird
{
private:

public:
  NormalBird(const Point & point);
  
  virtual void draw();
  virtual int hit();
};



class ToughBird : public Bird
{
private:
  int lives;
public:
  ToughBird(const Point & point);
  
  virtual void draw();
  virtual int hit();
};


class SacredBird : public Bird
{
private:

public:
  SacredBird(const Point & point);
  
  virtual void draw();
  virtual int hit();
};



#endif

