// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "polygon.hpp"
#include "vertice.hpp"
#include <math.h>
using namespace std;

void initializeCanvas(vector<vector<string>>& canvas, int sizex, int sizey)
{
    canvas.resize(sizex);
 
    for (int y = 0; y < sizey; y++)
    {
        for (int x = 0; x < sizex;x++)
        {
            canvas[x].resize(sizey);
            canvas[x][y] = ".";  
        }
    }
}

void printCanvas(vector<vector<string>> canvas, int sizex, int sizey)
{
    for (int y = sizey-1; y>0; y--)
    {
        for (int x = 0; x < sizex;x++)
        {
            cout << canvas[x][y];
        }
        cout << endl;
    }
    
}

void connect2Vertices(Vertice one, Vertice two, vector<vector<string>>& canvas)
{
   
    int deltax = two.x - one.x;
    int deltay = two.y - one.y;
    int deltaz = two.z - one.z;

    
    int upslash_count;
    int backslash_count;
    int dash_count;
    int slash_increment;
    int vert_bar_count;

    //Quadrant 1
    if (deltax > 0 && deltay > 0)
    {
        //less than 45 degrees.
        if (deltax >= deltay)
        {
            upslash_count = deltay;
            dash_count = deltax - upslash_count;
            slash_increment = deltax/deltay;
        }

        //greater than 45 degrees
        if (deltay > deltax)
        {
            upslash_count = deltax;
            vert_bar_count = deltay - upslash_count;
            slash_increment = deltay / deltax;

            int xinc = 0;//starts at 0 because we start with a vertical bar
            int yinc = 1; // starts at 1 because we start with a vertical bar
            //counter to mark when a slash should be entered
            int counter = 1;
            for (int i = 0; i >=deltay; i++)
            {
                if (counter < slash_increment)
                {
                    canvas[one.x + xinc][one.y + yinc] = "|";

                    yinc += 1;
                    counter += 1;
                    
                }
                if (counter >= slash_increment)
                {
                    xinc += 1;
                    canvas[one.x + xinc][one.y + yinc] = "/";
                    yinc += 1;
                    counter = 1;
                 
                }

            }
        }
        
    }
 



    if (deltax > 0)
    {

    }
}
int main()
{
    int sizex = 100;
    int sizey = 50;
    vector<vector<string>> canvas;
    initializeCanvas(canvas, sizex, sizey);
    


    Polygon triangle = Polygon(vector<Vertice> {Vertice(20, 0, 0), Vertice(60, 0, 0), Vertice(40, 40, 0) });
    connect2Vertices(triangle.vertices[0], triangle.vertices[2], canvas);
    printCanvas(canvas, sizex, sizey);
}



