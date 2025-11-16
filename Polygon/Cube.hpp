#ifndef CUBE
#define CUBE

#include <math.h>
#include "vertice.hpp"
#include "polygon.hpp"

class Cube
{
	Cube(int scalar, Vertice transform, int height);
	
	float r;
	int height;
	int scalar;
	Vertice transform;

	void rotate();
	vector<vector<Vertice>> faces;
	vector<int> E(int x, int y, int z);
	
};







#endif