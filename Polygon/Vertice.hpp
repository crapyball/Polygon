#ifndef VERTICE
#define VERTICE

class Vertice {

public:
	Vertice();
	Vertice(float px, float py, float pz);
	float x;
	float y;
	float z;
	
	float getx();
	float gety();
	float getz();
};

#endif