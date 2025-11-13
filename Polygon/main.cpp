// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "polygon.hpp"
#include "vertice.hpp"
using namespace std;

void initializeCanvas(vector<vector<string>> canvas, int sizex, int sizey)
{

    for (int x = 0; x < sizey; x++)
    {
        
        for (int y = 0; y < sizex;y++)
        {
            canvas[x][y] = ".";
            cout << canvas[x][y];
        }
        cout << endl;
    }

    

}

int main()
{
    int sizex = 20;
    int sizey = 10;
    vector<vector<string>> canvas(sizex, vector<string>(sizey));
    
    initializeCanvas(canvas, sizex, sizey);

}



