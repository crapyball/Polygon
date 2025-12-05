#ifndef QUEUE
#define QUEUE

#include <vector>
#include "vertice.hpp"
#include <string>
#include <iostream>

using namespace std;

class Queue
{
public: 
	float scale;
	int sizex;
	int sizey;
	vector<vector<string>> canvas;
	Queue(int x, int y);
	void setScale(float s);
	vector<int> convertTo2D(Vertice v);
	void initializeCanvas();
	void resetCanvas();
	void printCanvas();
	
};









#endif