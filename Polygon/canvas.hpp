#ifndef CANVAS
#define CANVAS

#include <vector>
#include <iostream>
#include "polygon.hpp"
using namespace std;

class Canvas
{
	public:
		Canvas(int sizex, int sizey);

		int sizex;
		int sizey;
		vector<vector<string>> canvas;
		vector<Polygon> polygons;
		void print();
};




#endif