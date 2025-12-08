#ifndef QUEUE
#define QUEUE

#include <vector>
#include "vertice.hpp"
#include <iostream>
#include <math.h>

using namespace std;

class Queue
{
public: 
	float scale;
	float rotation;

	float sizex;
	float sizey;
	float persAngle;

	float persX;
	float persY;
	float persZ;

	vector<vector<string>> canvas;

	vector<vector<Vertice>> faces;

	Queue(float widthx, float widthy, float angle);
	void setScale(float s);
	vector<int> convert2D(Vertice v);
	void initializeCanvas();
	void resetCanvas();
	void printCanvas();
	void connectVertices(vector<int> one, vector<int> two);
	void run();
	void addToQueue(vector<Vertice> v);

};









#endif