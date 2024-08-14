/*************************************************************************
flyingobject.h
*************************************************************************/

#ifndef flyingObject_h
#define flyingObject_h


#include "point.h"
#include "velocity.h"


class FlyingObject
{

protected:
	Point point;
	Velocity velocity;
	bool alive;

public:
	FlyingObject() { }
	virtual ~FlyingObject() { }
	
	Point getPoint() const        { return point;    }
	Velocity getVelocity () const { return velocity; }
	bool isAlive() const          { return alive;    }


	void setPoint(const Point & point)  { this->point = point;   }
	void setAlive(bool alive)   { this->alive = alive;   }
	void setVelocity(const Velocity & velocity) {this->velocity = velocity;}

	virtual void advance();
	virtual void draw() = 0;
        virtual void kill() { alive = false; }
	
};

#endif /* flyingObject_h */
