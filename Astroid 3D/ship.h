#include "asteroid.h"

#ifndef ship_h
#define ship_h



class Ship
{
public:
							Ship();
	 void				moveShip();
	 //Abstract
	 virtual void SuperWeapon() = 0;
	 virtual void regularWeapon() = 0;
	virtual void explode() = 0;

public:
	float  rotateX, rotateY, rotateZ;
	float  posX, posY, posZ;
	float  sizeX, sizeY, sizeZ;
	float  moveSpeed;
	int	  health;
	bool dead;
	int obj;
	//int life;
};



class Jet:public Ship
{
public:
	 Jet();
	 virtual void regularWeapon();
	 virtual void SuperWeapon();
	 virtual void explode();
};


class Bomber:public Ship
{
public:
	Bomber();
    virtual void regularWeapon();
	virtual void SuperWeapon();
	virtual void explode();
};

#endif