
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define DEFAULT_AMMO 100

#define THRUST_AMOUNT 0.1

#define SHIP_MOVE_AMOUNT 15
#define ROTATE_AMOUNT 6
#define ANGLE_UP 0
#define ANGLE_LEFT 90
#define ANGLE_DOWN 180
#define ANGLE_RIGHT 270

#define ANGLE_MAX 360
#define ANGLE_MIN 0

#include "point.h"
#include "velocity.h"


class Ship
{
private:
	Point point;
	Velocity velocity;
	bool alive;
        int ammo;
        float angle;

public:
	Ship() : point(point), alive(true), ammo(DEFAULT_AMMO), angle(ANGLE_MIN)
	{
	}
	
	Point getPoint() const        { return point;    }
	Velocity getVelocity () const { return velocity; }
	bool isAlive() const          { return alive;    }
	int getAmmo() const           { return ammo;     }
	float getAngle() const        { return angle;    }

	void setPoint(Point point)  { this->point = point; }
	void setAlive(bool alive)   { this->alive = alive; }
      
	bool canShoot();
	void useAmmo() { ammo -=1; }
	
	void setAmmo(int ammo)      { this->ammo  = ammo;  }
        void setAngle(int angle)    { this->angle = angle; }
        
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustUp();
	void applyThrustDown();
	
	// Change ship direction/aim
	void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

	void advance();
	void draw() const;
};


#endif /* ship_h */
