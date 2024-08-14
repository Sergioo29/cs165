
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define DEFAULT_FUEL 500

#include "point.h"
#include "velocity.h"


class Ship
{
private:
	Point point;
	Velocity velocity;
	bool alive;
	int fuel;

public:
	Ship() : point(0, 150), alive(true), fuel(DEFAULT_FUEL)
	{
	}
	
	Point getPoint() const        { return point;    }
	Velocity getVelocity () const { return velocity; }
	bool isAlive() const          { return alive;    }
	int getFuel() const           { return fuel;     }

	void setPoint(Point point)  { this->point = point;   }
	void setAlive(bool alive)   { this->alive = alive;   }
	void setFuel(int fuel)      { this->fuel = fuel;     }

	bool canThrust();
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustUp();
	void applyThrustBottom();

	void advance();
	void draw() const;
};


#endif /* ship_h */
