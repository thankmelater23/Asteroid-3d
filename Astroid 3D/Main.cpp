#include "DarkGDK.h"
#include "sc_collision.h" //loads sparkys collision  plugin
#include "function.h"
#include "defined.h"
#include "ship.h"
#include "asteroid.h"
#include "ufo.h"



void DarkGDK ( void )
{
	loadSettings();
	loadResources();

	//ASTEROID LOADED OBJECTS
	Large_Roid loadLarge(1);
	Big_Roid loadBig(1);
	Medium_Roid loadMedium(1);
	Small_Roid loadSmall(1);
	Tiny_Roid loadTiny(1);

	Ship *player = new Jet;

	Asteroid * roids[NUM_ASTEROIDS];
	setAsteroids(roids, NUM_ASTEROIDS);

	dbMakeObjectSphere(MACH_GUN_FIRE, 2);
	dbTextureObject(MACH_GUN_FIRE, MACH_GUN_FIRE);


	while ( LoopGDK ( ) )
	{
		astroReset(roids, NUM_ASTEROIDS);
		astroidPhysics(roids, NUM_ASTEROIDS);
		collision(roids, NUM_ASTEROIDS, player);
		player->moveShip();

		

		pause();
		if(dbSpaceKey())
		{
			dbWait(1000);
		}
		dbSync ( );
	}
	


	memoryLeak();
	return;
}