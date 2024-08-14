/***********************************************************************
 * Author:
 *    Sergio Henrique
 * Summary:
 *    This is the lander header.
 ************************************************************************/

#ifndef lander_h
#define lander_h

#include "point.h"
#include "velocity.h"

#define DEFAULT_FUEL 500

class Lander
{
private:
	Point point;
	Velocity velocity;
	bool alive;
	bool landed;
	int fuel;

public:
	Lander() : point(0, 150), alive(true), landed(false), fuel(DEFAULT_FUEL)
	{
	}
	Point getPoint() const        { return point;    }
	Velocity getVelocity () const { return velocity; }
	bool isAlive() const          { return alive;    }
	bool isLanded() const         { return landed;   }
	int getFuel() const           { return fuel;     }

	void setPoint(Point point)  { this->point = point;   }
	void setLanded(bool landed) { this->landed = landed; }
	void setAlive(bool alive)   { this->alive = alive;   }
	void setFuel(int fuel)      { this->fuel = fuel;     }

	void applyGravity(float amount);
	bool canThrust();
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();

	void advance();

	void draw() const;
};


#endif // UI_LANDER_H
