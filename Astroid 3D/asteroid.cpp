#include "asteroid.h"
#include "DarkGDK.h"
#include"defined.h"
#include "function.h"
#include "sc_collision.h" //loads sparkys collision  plugin
#include "ship.h"


//ASTEROID
Asteroid::Asteroid()
{
	rotateX = 0;
	rotateY = 0;
	rotateZ = 0;

	posX = 0;
	posY = 0;
	posZ = 0;

	sizeX = 0;
	sizeY = 0;
	sizeZ = 0;

	moveSpeed = 0;

	resetStroid = false;

	dLeft = false;
	dRight = false;
	dead = false;

	resetBool = false;
	resetTimer = 0;

	convertSpeed();
	convertWeight();
}

Asteroid::~Asteroid()
{
}
void Asteroid::gravity()
{
	dbPositionObject ( obj, dbObjectPositionX(obj), dbObjectPositionY(obj)+ totalSpeed, dbObjectPositionZ(obj));
	return;
}


void Asteroid::reset()
{
	posX = dbObjectPositionX(obj);
	posY = dbObjectPositionY(obj);
	posZ = dbObjectPositionZ(obj);

	if(posY <= -22 || posX  <= -25 || posX >= 25  || posY >= 35)
	{
	totalSpeed = moveSpeed + GAME_SPEED;
	dbPositionObject ( obj, dbRnd(47) -25 , dbRnd(10) +25 , 0);
	}
	return;
}


void Asteroid::oppositeSpeed()
{
	totalSpeed = dbABS(moveSpeed) + dbABS(GAME_SPEED);
}


void Asteroid::doubleSpeed()
{
	totalSpeed = (-dbABS(moveSpeed) + -dbABS(GAME_SPEED)) * 2;
}


void Asteroid::driftLeft()
{
	if(dLeft == true && dRight == false)
	{
		float x = dbObjectPositionX(obj);
		float y = dbObjectPositionY(obj);
		float z = dbObjectPositionZ(obj);
		dbPositionObject  						(obj, x + DRIFT_SPEED_L, y, z );
		dRight = false;
	}
}
void Asteroid::driftRight()
{
	if(dRight == true && dLeft == false)
	{
		float x = dbObjectPositionX(obj);
		float y = dbObjectPositionY(obj);
		float z = dbObjectPositionZ(obj);
		dbPositionObject(obj, x + DRIFT_SPEED_R, y, z );
		dLeft = false;
	}
}
void Asteroid::convertSpeed()
{
	int conv;

	if(moveSpeed == -.01)
		  {
			   conv = -1;
		  }
	else if(moveSpeed == -.02)
		  {
			   conv = -2;
		  }
	else if(moveSpeed == -.03)
		  {
			   conv = -3;
		  }
	else if(moveSpeed == -.04)
		  {
			   conv = -4;
		  }
	else if(moveSpeed == -.05)
		  {
			   conv = -5;
		  }
	else if(moveSpeed == -.06)
		  {
			   conv = -6;
		  }
	else if(moveSpeed == -.07)
		  {
			   conv = -7;
		  }
	else if(moveSpeed == -.08)
		  {
			   conv = -8; 
		  }
	else if(moveSpeed == -.09)
		  {
			   conv = -9;
		  }
	else if(moveSpeed == -.10)
		  {
			   conv = -10; 
		  }
	else if(moveSpeed == -.11)
		  {
			   conv = -11;
		  }
	else if(moveSpeed == -.12)
		  {
			   conv = -12;
		  }



	else if(moveSpeed == .01)
		  {
			   conv = 1;
		  }
	else if(moveSpeed == .02)
		  {
			   conv = 2;
		  }
	else if(moveSpeed == .03)
		  {
			   conv = 3;
		  }
	else if(moveSpeed == .04)
		  {
			   conv = 4;
		  }
	else if(moveSpeed == .05)
		  {
			   conv = 5;
		  }
	else if(moveSpeed == .06)
		  {
			   conv = 6;
		  }
	else if(moveSpeed == .07)
		  {
			   conv = 7;
		  }
	else if(moveSpeed == .08)
		  {
			   conv = 8; 
		  }
	else if(moveSpeed == .09)
		  {
			   conv = 9;
		  }
	else if(moveSpeed == .10)
		  {
			   conv = 10; 
		  }
	else if(moveSpeed == .11)
		  {
			   conv = 11;
		  }
	else if(moveSpeed == .12)
		  {
			   conv = 12;
		  }
		
	/*else
	{
		int error = 0;
		while(error == 0)
		{
		dbText(200, 200, "Error Astroid ConvertSpeed");
			if(dbSpaceKey())
			{
				error = 1;
			}
			dbSync();
		}
	calcSpeed = conv;
	
}*/
	}
void Asteroid::convertWeight()
{
	double conv;

	if(size == 1)
		  {
			   conv = 0.5;
		  }
	if(size == 2)
		  {
			   conv = 1.0;
		  }
	if(size == 3)
		  {
			   conv = 1.5;
		  }
	if(size == 4)
		  {
			   conv = 2.0;
		  }
	if(size == 5)
		  {
			   conv = 2.5;
		  }
		
	calcWeight = conv;
	
	
}
void Asteroid::onTopCollision(Asteroid * astro)
{
	convertSpeed();
	astro->convertSpeed();
	convertWeight();
	astro->convertWeight();

	double topSpd = calcSpeed;
	double botSpd = astro->calcSpeed;
	double topLb = calcWeight;
	double botLb = astro->calcWeight;
	
	if(topSpd < 0 && botSpd < 0)
	{
		botSpd = dbABS(botSpd);
		topSpd = dbABS(topSpd);

	    astro->moveSpeed = -(((topLb + topSpd) -topLb) + botSpd);
	    moveSpeed= (((topLb - topLb) + botSpd) - moveSpeed);

		if(moveSpeed < maxMoveSpeed && astro->moveSpeed < astro->maxMoveSpeed)
		{
			moveSpeed = maxMoveSpeed;
			astro->moveSpeed =astro->maxMoveSpeed;
		}
		
		if(moveSpeed > dbABS(maxMoveSpeed) && astro->moveSpeed > dbABS(astro->maxMoveSpeed))
		{
			moveSpeed = dbABS(maxMoveSpeed);
			astro->moveSpeed =dbABS(astro->maxMoveSpeed);
		}	

		botSpd = -(botSpd);
		topSpd = -(topSpd);
	}


	if(topSpd > 0 && botSpd > 0)
	{
		dbABS(botSpd);
		dbABS(topSpd);
	    astro->moveSpeed = (((topLb + topSpd) -botLb) + botSpd);
		moveSpeed= -(((topLb - topLb) + botSpd) - moveSpeed);//Not sure if correct
	}

}
void Asteroid::hitShip(Ship *player)
{
	player->health -= dmg;
	if(player->health <= 0)
	{
		player->dead = true;
		dead = true;
	}
}
//LARGE_ROID
Large_Roid::Large_Roid()
{
	obj = findFreeObject(100);
	dbCloneObject(obj, LARGE_OBJ);
	moveSpeed = LARGE_STROID_SPEED;
	totalSpeed = moveSpeed + GAME_SPEED;
	maxMoveSpeed = LARGE_STROID_MAX_SPEED;
	size = 5;
	health = 20;
	dmg = 2.0;
	SC_SetupObject(obj, 1, 2);
	//dbSetObjectAmbient ( ASTERIOD1, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, dbRnd(360) - 360, dbRnd(360) - 360, dbRnd(360) - 360 );
	dbPositionObject(obj, 0, -30,0);
	dbSetObjectCollisionToPolygons(obj );
}



Large_Roid::Large_Roid(int load)
{
	obj = LARGE_OBJ;
	dbLoadObject("asteroid//AST_01.X", obj);
	dbLoadImage( "asteroid//AST4.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, 5, 4, 7);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	dbHideObject(obj);
}
void Large_Roid::hit(Asteroid * astro)
{
	astro->health -= dmg;
	if(astro->health <= 0)
	{
		astro->dead = true;
		astro->deathType = DT_ASTEROID;
	}
}
void Large_Roid::explode()
{
	dbPlaySound(RUBBLE);
	dbDeleteObject(obj);
}


//BIG_ROID
Big_Roid::Big_Roid()
{
	obj = findFreeObject(100);
	dbCloneObject(obj, BIG_OBJ);
	moveSpeed = BIG_STROID_SPEED;
	totalSpeed = moveSpeed + GAME_SPEED;
	maxMoveSpeed = BIG_STROID_MAX_SPEED;
	size = 4;
	health = 15;
	dmg = 1.0;
	SC_SetupObject(obj, 1, 2);
	//dbSetObjectAmbient ( ASTERIOD2, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, dbRnd(360) - 360, dbRnd(360) - 360, dbRnd(360) - 360 );
	dbPositionObject(obj, -30, 4,0);
	dbSetObjectCollisionToPolygons(obj );
}


Big_Roid::Big_Roid(int load)
{
	obj = BIG_OBJ;
	dbLoadObject("asteroid//AST_03.X", obj);
	dbLoadImage( "asteroid//AST5.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, 4, 3, 6);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	dbHideObject(obj);
}
void Big_Roid::hit(Asteroid * astro)
{
	astro->health -= dmg;
	if(astro->health <= 0)
	{
		astro->dead = true;
		astro->deathType = DT_ASTEROID;
	}
}
void Big_Roid::explode()
{
	dbPlaySound(RUBBLE);
	dbDeleteObject(obj);
}



//MEDIUM_ROID
Medium_Roid::Medium_Roid()
{
	obj = findFreeObject(100);
	dbCloneObject(obj, MEDIUM_OBJ);
	moveSpeed = MEDIUM_STROID_SPEED;
	totalSpeed = moveSpeed + GAME_SPEED;
	maxMoveSpeed = MEDIUM_STROID_MAX_SPEED;
	size = 3;
	health = 10;
	dmg = 1.0;
	SC_SetupObject(obj, 1, 2);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, dbRnd(360) - 360, dbRnd(360) - 360, dbRnd(360) - 360 );
	dbPositionObject(obj, -30, 4,0);
	dbSetObjectCollisionToPolygons(obj );
}


Medium_Roid::Medium_Roid(int load)
{
	obj = MEDIUM_OBJ;
	dbLoadObject("asteroid//AST_02.X", obj);
	dbLoadImage( "asteroid//AST3.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, 3, 3, 5);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	dbHideObject(obj);
}
void Medium_Roid::hit(Asteroid * astro)
{
	astro->health -= dmg;
	if(astro->health <= 0)
	{
		astro->dead = true;
		astro->deathType = DT_ASTEROID;
	}
}
void Medium_Roid::explode()
{
	dbPlaySound(RUBBLE);
	dbDeleteObject(obj);
}



//SMALL_ROID
Small_Roid::Small_Roid()
{
	obj = findFreeObject(100);
	dbCloneObject(obj, SMALL_OBJ);
	moveSpeed = SMALL_STROID_SPEED;
	totalSpeed = moveSpeed + GAME_SPEED;
	maxMoveSpeed = SMALL_STROID_MAX_SPEED;
	size = 2;
	health = 7;
	dmg = .5;
	SC_SetupObject(obj, 1, 2);
	//dbSetObjectAmbient ( ASTERIOD4, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, dbRnd(360) - 360, dbRnd(360) - 360, dbRnd(360) - 360 );
	dbPositionObject(obj, -30, 4,0);
	dbSetObjectCollisionToPolygons(obj );

}


Small_Roid::Small_Roid(int load)
{
	obj = SMALL_OBJ;
	dbLoadObject("asteroid//AST_04.X", obj);
	dbLoadImage( "asteroid//AST1.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, 2, 3, 3);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	dbHideObject(obj);
}
void Small_Roid::hit(Asteroid * astro)
{
	astro->health -= dmg;
	if(astro->health <= 0)
	{
		astro->dead = true;
		astro->deathType = DT_ASTEROID;
	}
}
void Small_Roid::explode()
{
	dbPlaySound(RUBBLE);
	dbDeleteObject(obj);
}



//TINY_ROID
Tiny_Roid::Tiny_Roid()
{
	obj = findFreeObject(100);
	dbCloneObject(obj, TINY_OBJ);
	moveSpeed = TINY_STROID_SPEED;
	totalSpeed = moveSpeed + GAME_SPEED;
	maxMoveSpeed = TINY_STROID_MAX_SPEED;
	size = 1;
	health = 5;
	dmg = .5;
	SC_SetupObject(obj, 1, 2);
	//dbSetObjectAmbient ( ASTERIOD5, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, dbRnd(360) - 360, dbRnd(360) - 360, dbRnd(360) - 360 );
	dbPositionObject(obj, -30, 4,0);
	dbSetObjectCollisionToPolygons(obj );
}


Tiny_Roid::Tiny_Roid(int load)
{
	obj = TINY_OBJ;
	dbLoadObject("asteroid//AST_05.X", obj);
	dbLoadImage( "asteroid//AST2.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, 2, 2, 2);
	//dbSetObjectAmbient ( ASTERIOD3, 0 );
	dbHideObject(obj);
}
void Tiny_Roid::hit(Asteroid * astro)
{
	astro->health -= dmg;
	if(astro->health <= 0)
	{
		astro->dead = true;
		astro->deathType = DT_ASTEROID;
	}
}
void Tiny_Roid::explode()
{
	dbPlaySound(RUBBLE);
	dbDeleteObject(obj);
}
