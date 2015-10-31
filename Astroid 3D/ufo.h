#ifndef ufo_h
#define ufo_h



class Ufo
{
public:
	float rotateX, rotateY, rotateZ;
	float posX, posY, posZ;
	float sizeX, sizeY, sizeZ;
	float moveSpeed;
	int	 life;
	bool dead;
};



class SpaceCraft:public Ufo
{
public:
	SpaceCraft();
};
#endif