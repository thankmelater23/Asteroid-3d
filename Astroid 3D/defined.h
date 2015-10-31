#ifndef defined_h
#define defined_h



//Game Settings
#define SCREEN_X													500
#define SCREEN_Y													800
#define SYNC_RATE												60
#define MAP_X															500
#define MAP_Y														    800
#define GAME_SPEED											-0.20
#define CAMERA_POSITION_Z							-35
#define TOP_OUT_OF_BOUNDS_Y 
#define BOTTOM_OUT_OF_BOUNDS_Y 
#define LEFT_OUT_OF_BOUNDS_Y 
#define RIGHT_OUT_OF_BOUNDS_Y 
#define DRIFT_SPEED_R									.2
#define DRIFT_SPEED_L									   -.2
#define BOUNCE_BACK_OPPOSITE_VOID -15
//Death Type
#define DT_ASTEROID 1
#define DT_BULLETS	 2
#define DT_MISSLE		 3

//Asteroid Load Objedts
#define LARGE_OBJ	  75
#define BIG_OBJ			  76
#define MEDIUM_OBJ 77
#define SMALL_OBJ	  78
#define TINY_OBJ		  79

//Objects/Images
#define MAP					  1
#define SHIP					  2
#define ENEMY_SHIP 3
//Asteroids = 100+


//Images (Start at #20)
#define HNG 23
#define MACH_GUN_FIRE 300

//Running Game Settings
#define NUM_ASTEROIDS 20
//Asteroid Speed
#define LARGE_STROID_SPEED		-.01
#define BIG_STROID_SPEED		    -.02
#define MEDIUM_STROID_SPEED -.04
#define SMALL_STROID_SPEED	    -.05
#define TINY_STROID_SPEED			-.06
//MaxSpeed
#define LARGE_STROID_MAX_SPEED		( LARGE_STROID_SPEED	  * 3)
#define BIG_STROID_MAX_SPEED				( BIG_STROID_SPEED		      * 3)
#define MEDIUM_STROID_MAX_SPEED	( MEDIUM_STROID_SPEED * 3)
#define SMALL_STROID_MAX_SPEED		 (SMALL_STROID_SPEED	  * 3)
#define TINY_STROID_MAX_SPEED			 (TINY_STROID_SPEED		  * 3)


//Sound
#define ASTRO_COLLIDE		  1
#define RUBBLE							  2
#define ASTEROID_HIT_SHIP 3


#endif