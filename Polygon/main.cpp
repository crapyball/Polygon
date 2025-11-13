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


    int upslash_count = 0;
    int backslash_count = 0;
    int dash_count = 0;
    int slash_increment = 0;
    int vert_bar_count = 0;

    //Quadrant 1
    if (deltax > 0 && deltay > 0)
    {
        //less than 45 degrees.
        if (deltax >= deltay)
        {
            upslash_count = deltay;
            dash_count = deltax - upslash_count;
            slash_increment = deltax / deltay;

            int xinc = 1;//starts at 1 because we start with a horizontal bar
            int yinc = 0; // starts at 0 because we start with a horizontal bar
            //counter to mark when a slash should be entered
            int counter = 1;
            for (int i = 0; i < deltax; i++)
            {
                if (counter < slash_increment)
                {
                    canvas[one.x + xinc][one.y + yinc] = "-";

                    xinc += 1;
                    counter += 1;

                }
                else if (counter >= slash_increment)
                {
                    yinc += 1;
                    canvas[one.x + xinc][one.y + yinc] = "-";
                    xinc += 1;
                    counter = 1;

                }
                cout << "deltay" << deltay << endl;
                cout << "xinc" << xinc << endl;
                cout << "yinc" << yinc << endl;

            }
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
            for (int i = 0; i < deltay; i++)
            {
                if (counter < slash_increment)
                {
                    canvas[one.x + xinc][one.y + yinc] = "|";

                    yinc += 1;
                    counter += 1;

                }
                else if (counter >= slash_increment)
                {
                    xinc += 1;
                    canvas[one.x + xinc][one.y + yinc] = "|";
                    yinc += 1;
                    counter = 1;

                }
                cout << "deltay" << deltay << endl;
                cout << "xinc" << xinc << endl;
                cout << "yinc" << yinc << endl;

            }
            
        }
        
    }

    //Quadrant 2
    if (deltax > 0 && deltay < 0)
    {
        //greater than -45 degrees
        if (deltax >= abs(deltay))
        {
            backslash_count = deltay;
            dash_count = abs(deltax - backslash_count);
            slash_increment = abs(deltax / deltay);
            

            int xinc = 1;//starts at 1 because we start with a horizontal bar
            int yinc = 0; // starts at 0 because we start with a horizontal bar
            //counter to mark when a slash should be entered
            int counter = 1;
            for (int i = 0; i < deltax; i++)
            {
                if (counter < slash_increment)
                {
                    canvas[one.x + xinc][one.y - yinc] = "-";

                    xinc += 1;
                    counter += 1;

                }
                else if (counter >= slash_increment)
                {
                    yinc += 1;
                    canvas[one.x + xinc][one.y - yinc] = "-";
                    xinc += 1;
                    counter = 1;

                }
                cout << "deltay" << deltay << endl;
                cout << "xinc" << xinc << endl;
                cout << "yinc" << yinc << endl;

            }
        }
        // less than -45 degrees
        if (abs(deltay) > deltax)
        {
            backslash_count = deltax;
            vert_bar_count = abs(deltay) - backslash_count;
            slash_increment = abs(deltay / deltax);

            int xinc = 0;//starts at 0 because we start with a vertical bar
            int yinc = 1; // starts at 1 because we start with a vertical bar
            //counter to mark when a slash should be entered
            int counter = 1;
            for (int i = 0; i < abs(deltay); i++)
            {
                if (counter < slash_increment)
                {
                    canvas[one.x + xinc][one.y - yinc] = "|";

                    yinc += 1;
                    counter += 1;

                }
                else if (counter >= slash_increment)
                {
                    xinc += 1;
                    canvas[one.x + xinc][one.y - yinc] = "|";
                    yinc += 1;
                    counter = 1;

                }
                cout << "deltay" << deltay << endl;
                cout << "xinc" << xinc << endl;
                cout << "yinc" << yinc << endl;

            }

            cout << "upslash count: " << upslash_count << endl;
            cout << "backslash count: " << backslash_count << endl;
            cout << "dash coun: " << dash_count << endl;
            cout << "slash increment: " << slash_increment << endl;
            cout << "vert bar count: " << vert_bar_count << endl;
        }

        
    }

}
/*
cout << "upslash count: " << upslash_count << endl;
            cout << "backslash count: " << backslash_count << endl;
            cout << "dash coun: " << dash_count << endl;
            cout << "slash increment: " << slash_increment << endl;
            cout << "vert bar count: " << vert_bar_count << endl;
*/
 



    
    

int main()
{
    int sizex = 100;
    int sizey = 50;
    vector<vector<string>> canvas;
    initializeCanvas(canvas, sizex, sizey);
    

    Polygon triangle = Polygon(vector<Vertice> {Vertice(25, 25, 0), Vertice(25, 0, 0), Vertice(30, 0, 10) });
    connect2Vertices(triangle.vertices[0], triangle.vertices[2], canvas);
    printCanvas(canvas, sizex, sizey);
}



