

#ifndef POLYGON
#define POLYGON

#include "vertice.hpp"
#include <vector>
#include <iostream>
using namespace std;


class Polygon {
	
	public:
		//constructor
		Polygon(int pnumvertices, vector<Vertice> pvertices);

		//vars
		int numvertices;
		vector<Vertice> vertices;

		void printVerticesLocations();
};

#endif