#include "ufo.h"
#include "DarkGDK.h"
#include "sc_collision.h" //loads sparkys collision  plugin
#include "function.h"
#include "defined.h"


SpaceCraft::SpaceCraft()
{
	dbLoadObject("ufo//ufo//Ship.X", ENEMY_SHIP);
	dbLoadImage( "ufo//ufo//SHIP.TGA",ENEMY_SHIP );
	dbTextureObject(ENEMY_SHIP,ENEMY_SHIP);
	SC_SetupObject(ENEMY_SHIP, 1, 2);
	SC_AllowObjectScaling(ENEMY_SHIP);
	dbScaleObject(ENEMY_SHIP, 1, 2, 3);
	dbSetObjectAmbient ( ENEMY_SHIP, 0 );
	SC_UpdateObject(ENEMY_SHIP); //updates the map's collision box
	dbRotateObject (ENEMY_SHIP, 180, 0, -90 );
	dbPositionObject(ENEMY_SHIP, 0, -10,0);
}