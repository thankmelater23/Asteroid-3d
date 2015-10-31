#include "DarkGDK.h"
#include"defined.h"
#include "function.h"
#include "sc_collision.h" //loads sparkys collision  plugin
#include "asteroid.h"




void loadSettings()
{
	dbSyncOn   ( );
	dbSyncRate ( SYNC_RATE );
	dbSetWindowTitle("Asteroids 3D");
	dbLoadImage("Hng Studio.bmp", HNG);

	while(!dbSpaceKey())
	{
	dbSprite(HNG, 22, 200, HNG);
	dbText(210, 70, "WELCOME TO \"Asteroids 3D\"");
	dbText(135, 100, "Developed by: Andre Villanueva(HnG Studios)");
	dbText(220, 120, "Created on: May 24, 2012");
	dbText(270, 140, "Game #2(3D)");
	dbSync();
	}
	dbDeleteImage(HNG);
	
	dbRandomize ( dbTimer ( ) );
	dbSetDisplayMode(SCREEN_X, SCREEN_Y, 32);
	dbSetWindowPosition(0,0 );
	dbAutoCamOff(); //stops stupid ass objects from moving the camera when they are loaded
	dbPositionCamera				( 0,0,CAMERA_POSITION_Z );
	dbBackdropOff();
	SC_Start();

	
}


void loadResources()
{
	//MAP
	dbLoadImage("map//Backdrop.bmp", MAP);
	dbSprite(MAP, 0,0,MAP);
	dbSizeSprite(MAP, SCREEN_X, SCREEN_Y);
	dbDrawToBack();

	//IMAGES
	dbLoadImage("images//gunfireMade.png", MACH_GUN_FIRE);
	

	
	
	//SOUND
	dbLoadSound("sound//explo//crash.wav", ASTRO_COLLIDE);
	dbLoadSound("sound//explo//rubble.wav", RUBBLE);
	dbLoadSound("sound//explo//scudbang.wav", ASTEROID_HIT_SHIP);


}


void memoryLeak()
{
	for(int i = 0; i < 100; i++)
	{
	dbDeleteImage(i);
	dbDeleteSprite(i);
	dbDeleteObject(i);
	dbDeleteSound(i);
	dbDeleteMusic(i);
	}

	return;
}


void playSound(int sound)
{
	if(dbSoundPlaying(sound))
			{
				dbStopSound(sound);
			}

			dbPlaySound(sound);
			
}

void pause()
{
	if(dbShiftKey  ())
		{
			dbWaitKey();
		}
}


void hud()
{

}


void spinRoids()
{
	for(int i = 100; i < 200; i++)
	{
		if(dbObjectExist(i))
		{
			dbRotateObject    						(i, dbObjectAngleX (i)- 2, dbObjectAngleY(i), dbObjectAngleZ (i));
			dbRollObjectLeft  						(i,2 );
		}
	}
	return;
}


int findFreeObject(int start)
{
	int freeObj=start;
	while (dbObjectExist(freeObj))
	{ 
		freeObj++;
	}
	return freeObj;
}


Asteroid* createRndStroid()
{
	int astro = dbRND(4);;

	switch(astro)
	{
	case 0:
		{
			if(dbRND(3) == 1)
			{
			return new Large_Roid();
			}
			else return new Medium_Roid();
			break;
		}
	case 1:
		{
			return new Big_Roid();
			break;
		}
	case 2:
		{
			return new Medium_Roid();
			break;
		}
	case 3:
		{
			return new Small_Roid();
			break;
		}
	case 4:
		{
			if(dbRND(3) == 1)
			{
			return new Tiny_Roid();
			}
			else return new Small_Roid();
			break;
		}
	default:
		{
			return new Medium_Roid();
			break;
		}

		}
}


void setAsteroids(Asteroid *roids[], int num)
{
	for(int i = 0; i < num; i++)
	{
		roids[i] = createRndStroid();
	}
}

void astroidPhysics(Asteroid *roids[], int num)
{
	spinRoids();

	for(int i = 0; i < num; i++)
	{

		if(roids[i]->dead == true)
		{
			roids[i]->explode();
		}

		roids[i]->gravity();
		//roids[i]->reset();

		roids[i]->driftLeft();
		roids[i]->driftRight();



		if(dbSpaceKey())
		{
		for(int i = 0; i < num; i++)
	{
		roids[i]->totalSpeed  += 0.01;
		}
		}
	}
	return;
}

void collision(Asteroid *stroid[], int num, Ship *player)
{

	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
	{
		int x = dbObjectPositionX(stroid[i]->obj);
		int y = dbObjectPositionY(stroid[i]->obj);
		int z = dbObjectPositionZ(stroid[i]->obj);

		if(dbObjectCollision(player->obj, stroid[j]->obj))//Ship Asteroid Collision
		{
			dbPlaySound(ASTEROID_HIT_SHIP);
			stroid[j]->hitShip(player);
			player->explode();

		}
		

		if(dbObjectCollision(stroid[i]->obj, stroid[j]->obj) && stroid[i]->obj != stroid[j]->obj)
		{
			
			//Objects Take Damage
			if(stroid[i]->posY <= 22 && stroid[j]->posY <= 22 && stroid[j]->posY  >= -20 && stroid[i]->posY  >=-20)
			{
				playSound(ASTRO_COLLIDE);
				stroid[i]->hit(stroid[j]);
				stroid[j]->hit(stroid[i]);
			}

			//playSound(ASTRO_COLLIDE);

			if(stroid[i]->posX < stroid[j]->posX)
				{
					stroid[i]->dLeft	= true;
					stroid[i]->dRight = false;
					stroid[j]->dRight = true;
					stroid[j]->dLeft	= false;

				}

				if(stroid[j]->posX < stroid[i]->posX)
				{
					stroid[j]->dLeft	= true;
					stroid[j]->dRight = false;
					stroid[i]->dRight = true;
					stroid[i]->dLeft	= false;

				}

				if(stroid[j]->posX == stroid[i]->posX)
				{
					stroid[j]->dLeft	= false;
					stroid[j]->dRight = false;
					stroid[i]->dRight = false;
					stroid[i]->dLeft	= false;

				}
			
			if(stroid[i]->posY < stroid[j]->posY)
			{
				

				if(stroid[i]->size > stroid[j]->size)
				{
					if(stroid[j]->posY  >= BOUNCE_BACK_OPPOSITE_VOID)
					{
					stroid[j]->oppositeSpeed();	
					}
					stroid[i]->dRight = false;
					stroid[i]->dLeft	= false;
				}
				if(stroid[i]->size < stroid[j]->size)
				{
					stroid[i]->doubleSpeed();
					stroid[j]->dRight = false;
					stroid[j]->dLeft	= false;
				}
				if(stroid[i]->size == stroid[j]->size)
				{
					if(stroid[j]->posY  >= BOUNCE_BACK_OPPOSITE_VOID)
					{
					stroid[j]->oppositeSpeed();	
					}
					stroid[i]->doubleSpeed();
				}
				
			}
			//playSound(ASTRO_COLLIDE);

			if(stroid[j]->posY < stroid[i]->posY)
			{

				if(stroid[j]->size > stroid[i]->size)
				{
					if(stroid[i]->posY  >= BOUNCE_BACK_OPPOSITE_VOID)
					{
					stroid[i]->oppositeSpeed();	
					}
					stroid[j]->dRight = false;
					stroid[j]->dLeft	= false;
				}
				if(stroid[j]->size < stroid[i]->size)
				{
					stroid[j]->doubleSpeed();
					stroid[i]->dRight = false;
					stroid[i]->dLeft	= false;
				}
				if(stroid[j]->size == stroid[i]->size)
				{
					if(stroid[i]->posY  >= BOUNCE_BACK_OPPOSITE_VOID)
					{
					stroid[i]->oppositeSpeed();	
					}
					stroid[j]->doubleSpeed();
				}
				
			}
		}
	/*	if(dbObjectCollision(stroid[i]->obj, stroid[j]->obj) && stroid[i]->obj != stroid[j]->obj  && stroid[i]->posY > 22 && stroid[j]->posY > 22  )
		{
			stroid[i]->reset();
			stroid[j]->reset();
		}*/
		}

	}

}
void astroReset(Asteroid *roids[], int num)
{

	for(int i = 0; i < num; i++)
	{
	roids[i]->posX = dbObjectPositionX(roids[i]->obj);
	roids[i]->posY = dbObjectPositionY(roids[i]->obj);
	roids[i]->posZ = dbObjectPositionZ(roids[i]->obj);

	if(roids[i]->posY <= -25 || roids[i]->posX  <= -32 || roids[i]->posX >= 32  || roids[i]->posY >= 38 && dbObjectExist(roids[i]->obj))
	{
		dbDeleteObject(roids[i]->obj);
		roids[i] = createRndStroid();
		roids[i]->totalSpeed = roids[i]->moveSpeed + GAME_SPEED;
		dbPositionObject ( roids[i]->obj, dbRnd(45) -25 , dbRnd(10) +28 , 0);
	}

	if(!dbObjectExist(roids[i]->obj))
	{
		roids[i] = createRndStroid();
		roids[i]->totalSpeed = roids[i]->moveSpeed + GAME_SPEED;
		dbPositionObject ( roids[i]->obj, dbRnd(45) -25 , dbRnd(10) +28 , 0);
	}
	}
	return;
}