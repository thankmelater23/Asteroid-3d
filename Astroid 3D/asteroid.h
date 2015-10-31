#ifndef asteroid_h
#define asteroid_h

#include "ship.h"

class Asteroid
{
public:
	friend void spinRoids();
	//friend void collision(Asteroid *stroid[], int num);

public:
						  Asteroid();
						  ~Asteroid();
	void			  gravity();
	void			  reset();
	void			  doubleSpeed();
	void			  oppositeSpeed();
	void			  driftRight();
	void			  driftLeft();
	void			  convertSpeed();
	void			  convertWeight();
	void			  onTopCollision(Asteroid * astro);
	void			  hitShip(Ship *player);
	//Abstract
	virtual void explode() = 0;
	virtual void	   hit(Asteroid * astro) = 0;
	

public:
	int	  obj;
	float  rotateX, rotateY, rotateZ;
	float  posX, posY, posZ;	//Responsible for collision and position of asteroid
	float  sizeX, sizeY, sizeZ;
	float  moveSpeed;
	float  totalSpeed;
	float	  health;
	float	  dmg;
	bool dead;
	int	  size;
	bool resetStroid;
	bool dLeft;
	bool dRight;
	double	  calcSpeed;
	double	  calcWeight;
	double	  maxMoveSpeed;
	bool			resetBool;
	double		resetTimer;
	int				deathType;

};


//Derived Asteroid Classes
class Large_Roid:public Asteroid
{
public:
	Large_Roid();
	Large_Roid(int load);
	virtual void hit(Asteroid *astro);
	virtual void explode();
};


class Big_Roid:public Asteroid
{
public:
	Big_Roid();
	Big_Roid(int load);
	virtual void hit(Asteroid *astro);
	virtual void explode();
};


class Medium_Roid:public Asteroid
{
public:
	Medium_Roid();
	Medium_Roid(int load);
	virtual void hit(Asteroid *astro);
	virtual void explode();
};


class Small_Roid:public Asteroid
{
public:
	Small_Roid();
	Small_Roid(int load);
	virtual void hit(Asteroid *astro);
	virtual void explode();
};


class Tiny_Roid:public Asteroid
{
public:
	Tiny_Roid();
	Tiny_Roid(int load);
virtual void hit(Asteroid *astro);
	virtual void explode();
};


#endif