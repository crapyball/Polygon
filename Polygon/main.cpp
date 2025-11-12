// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
#include "polygon.hpp"
#include "vertice.hpp"
using namespace std;
int main()
{
    vector<Vertice> square = { Vertice(0,0,0),Vertice(100,0,0) ,Vertice(0,100,0) ,Vertice(100,100,0) };

    Polygon canvas = Polygon(4, square);
    canvas.printVerticesLocations();

}

