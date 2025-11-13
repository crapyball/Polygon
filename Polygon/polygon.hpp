

#ifndef POLYGON
#define POLYGON

#include "vertice.hpp"
#include <vector>
#include <iostream>
using namespace std;


class Polygon {
	
	public:
		//constructor
		Polygon(vector<Vertice> pvertices);

		//vars
		
		vector<Vertice> vertices;

		void printVerticesLocations();
		
};


#endif