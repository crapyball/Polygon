#ifndef VERTICE
#define VERTICE

class Vertice {

public:
	Vertice();
	Vertice(int px, int py, int pz);
	int x;
	int y;
	int z;
	
	int getx();
	int gety();
	int getz();
};

#endif