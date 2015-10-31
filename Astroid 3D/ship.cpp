#include "ship.h"
#include "defined.h"
#include "DarkGDK.h"
#include "sc_collision.h" //loads sparkys collision  plugin

//SHIP
Ship::Ship()
{
	rotateX = 0;
	rotateY = 0;
	rotateX = 0;
	obj = SHIP;

	
}
void Ship::moveShip()
{
	//Add Tilt
	posX = dbObjectPositionX(SHIP);
	posY = dbObjectPositionY(SHIP);
	posZ = dbObjectPositionZ(SHIP);

	

	double a = 0;
	\
	if(dbLeftKey() && posX >= -24)
		{
			a -= .7;
			dbPositionObject( SHIP, posX - moveSpeed, posY, posZ );
		}

		if(dbRightKey() && posX <= 24)
		{
			a+= .7;
			dbPositionObject( SHIP, posX + moveSpeed, posY, posZ );
		}

		dbPositionObject(MACH_GUN_FIRE, posX + a , posY + 2, + 1);//Machine Gun Fire
}

//JET
Jet::Jet()
{
	rotateX = 60;
	rotateY = 180;
	rotateZ = 0;

	posX = 0;
	posY =-18;
	posZ = 0;

	sizeX = 40;
	sizeY = 40;
	sizeZ = 20;

	health = 20;

	moveSpeed = 0.7;

	dbLoadObject("ship//H-Jet Fighter Blank-Move.x", obj);
	dbLoadImage( "ship//JetBlank.dds",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, sizeX, sizeY, sizeZ);
	dbSetObjectAmbient ( obj, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, rotateX, rotateY, rotateZ );
	dbPositionObject(obj, posX, posY ,posZ);
	dbSetObjectCollisionToPolygons			(obj );
}

void Jet::regularWeapon()
{
}
void Jet::SuperWeapon()
{
}
void Jet::explode() 
{
	if(dead == true)
	{
	}
}
//BOMBER
Bomber::Bomber()
{
	rotateX = 90;
	rotateY = 180;
	rotateZ = -90;

	posX = 0;
	posY =-16;
	posZ = 0;

	sizeX = 12;
	sizeY = 15;
	sizeZ = 10;

	health = 20;

	moveSpeed = 0.1;

	dbLoadObject("ship//AIRPL003//AIRPL003.X", obj);
	dbLoadImage( "ship//AIRPL003//GB2.BMP",obj );
	dbTextureObject(obj,obj);
	SC_SetupObject(obj, 1, 2);
	SC_AllowObjectScaling(obj);
	dbScaleObject(obj, sizeX, sizeY, sizeZ);
	dbSetObjectAmbient ( obj, 0 );
	SC_UpdateObject(obj); //updates the map's collision box
	dbRotateObject (obj, rotateX, rotateY, rotateZ );
	dbPositionObject(obj, posX, posY ,posZ);
	dbSetObjectCollisionToPolygons(obj );
}
void Bomber::regularWeapon()
{
}
void Bomber::SuperWeapon()
{
}
void Bomber::explode()
{
	if(dead == true)
	{
	}
}