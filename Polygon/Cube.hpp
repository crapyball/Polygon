#ifndef CUBE
#define CUBE

#include <math.h>
#include "vertice.hpp"
#include "polygon.hpp"

class Cube
{
	public:
		Cube(float scalar, Vertice transform, int height);
	
		float r;
		int height;
		float scalar;
		Vertice transform;
		vector<vector<Vertice>> faces;

		vector<vector<Vertice>> rotate(float rotation);
		void print();
		vector<int> E(float x, float y, float z);
	
};







#endif