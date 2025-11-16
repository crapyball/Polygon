

#ifndef POLYGON
#define POLYGON

#include "vertice.hpp"
#include <vector>
#include <iostream>
using namespace std;


class Polygon {
	
	public:
		//constructor
		Polygon(vector<Vertice> pface1);

		//vars
		
		vector<Vertice> face1;

		void printface1Locations();
		
};


#endif