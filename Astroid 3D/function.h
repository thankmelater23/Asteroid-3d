#ifndef function_h
#define function_h

#include "defined.h"
#include "asteroid.h"
#include "ship.h"



void			loadSettings			();
void			loadResources		();
void			memoryLeak			();
void			playSound				(int sound);
void			pause						();
void			hud								();
void			spinRoids				();
int				findFreeObject		(int start);
void			collision					(Asteroid *stroid[], int num, Ship *player);
void			setAsteroids			(Asteroid *[], int num);
void			astroidPhysics		(Asteroid *roids[], int num);
void			astroReset				(Asteroid *roids[], int num);
Asteroid*  createRndStroid	();

#endif