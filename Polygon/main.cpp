// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "polygon.hpp"
#include "vertice.hpp"
#include <math.h>
#include "cube.hpp"
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;

void initializeCanvas(vector<vector<string>>& canvas, int sizex, int sizey)
{
    canvas.resize(sizex);
 
    for (int y = 0; y < sizey; y++)
    {
        for (int x = 0; x < sizex;x++)
        {
            canvas[x].resize(sizey);
            canvas[x][y] = " ";  
        }
    }
}



void resetCanvas(vector<vector<string>>& canvas)
{
    for (int y = 0; y < canvas[0].size(); y++)
    {
        for (int x = 0; x < canvas.size();x++)
        {
            canvas[x][y] = " ";
        }
    }
}

void printCanvas(vector<vector<string>> canvas, int sizex, int sizey)
{
    for (int i = 0; i < sizex +2; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int y = canvas[0].size() - 1; y>0; y--)
    {
        cout << "|";
        for (int x = 0; x < canvas.size() ;x++)
        {
            cout  << canvas[x][y];
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < sizex+2; i++)
    {
        cout << "-";
    }
    
}

void connectVertices(Vertice one, Vertice two, vector<vector<string>>& canvas)
{
    //if on the same point
    if (one.x == two.x && one.y == two.y)
    {
       
        return;
    }

    int deltax = two.x - one.x;
    int deltay = two.y - one.y;
    int deltaz = two.z - one.z;


    int shift_count = 0;
    int dash_count = 0;
    int shift_increment = 0;
    int vert_bar_count = 0;
    bool is_horizontal = false;
    bool is_vertical = false;

    //Quadrant 1
    if (deltax >= 0 && deltay >= 0)
    {
        //less than 45 degrees (0 to 45)
        if (deltax >= deltay)
        {
            shift_count = deltay;
            dash_count = deltax - shift_count;
            if (deltay == 0)
            {
                is_horizontal = true;
                
            }
            else {
                shift_increment = deltax / deltay;
                is_horizontal = false;
            }
            


            int xinc = 1;//starts at 1 because we start with a horizontal bar
            int yinc = 0; // starts at 0 because we start with a horizontal bar
            //shift_counter to mark when a slash should be entered
            int shift_counter = 1;
            for (int i = 0; i < deltax; i++)
            {
                if (shift_counter < shift_increment || is_horizontal)
                {
                    canvas[one.x + xinc][one.y + yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment && !is_horizontal)
                {
                    yinc += 1;
                    canvas[one.x + xinc][one.y + yinc] = "-";
                    xinc += 1;
                    shift_counter = 1;

                }
                
            }
        }
        
        //greater than 45 degrees (45 to 90)
        if (deltay > deltax)
        {
            shift_count = deltax;
            vert_bar_count = deltay - shift_count;
            if (deltax == 0)
            {
                is_vertical = true;

            }
            else {
                shift_increment = deltay / deltax;
                is_vertical = false;
            }

            int xinc = 0;
            int yinc = 1; 
            
            int shift_counter = 1;
            for (int i = 0; i < deltay; i++)
            {
                if (shift_counter < shift_increment || is_vertical)
                {
                    canvas[one.x + xinc][one.y + yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment && !is_vertical)
                {
                    xinc += 1;
                    canvas[one.x + xinc][one.y + yinc] = "|";
                    yinc += 1;
                    shift_counter = 1;

                }
            

            }
            
        }
        
    }
    if (deltax < 0 && deltay > 0)
    {
        // (90 to 135)
        if (abs(deltay) > abs(deltax))
        {
            shift_count = abs(deltax);
            vert_bar_count = abs(deltay) - shift_count;
            shift_increment = abs(deltay / deltax);

        


            int xinc = 0;
            int yinc = 1;

            int shift_counter = 1;
            for (int i = 0; i < abs(deltay); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one.x - xinc][one.y + yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment)
                {
                    xinc += 1;
                    canvas[one.x - xinc][one.y + yinc] = "|";
                    yinc += 1;
                    shift_counter = 1;

                }
               
            }
        }

        //135 to 180
        if (abs(deltax) > deltay)
        {
            shift_count = deltay;
            dash_count = abs(deltax - shift_count);
            shift_increment = abs(deltax / deltay);


            int xinc = 1;
            int yinc = 0;

            int shift_counter = 1;
            for (int i = 0; i < abs(deltax); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one.x - xinc][one.y + yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment)
                {
                    yinc += 1;
                    canvas[one.x - xinc][one.y + yinc] = "-";
                    xinc += 1;
                    shift_counter = 1;

                }

            }
        }
    }

    

    //Quadrant 3
    if (deltax <= 0 && deltay <= 0)
    {
        // 180 to 225
        if (abs(deltax) >= abs(deltay))
        {
            shift_count = abs(deltay);
            dash_count = abs(deltax) - shift_count;
            if (deltay == 0)
            {
                is_horizontal = true;
                
                
            }
            else {
                shift_increment = abs(deltax / deltay);
                is_horizontal = false;
            }
            
            int xinc = 1;//starts at 1 because we start with a horizontal bar
            int yinc = 0; // starts at 0 because we start with a horizontal bar
            //shift_counter to mark when a slash should be entered
            int shift_counter = 1;
            for (int i = 0; i < abs(deltax); i++)
            {
                if (shift_counter < shift_increment || is_horizontal)
                {
                    canvas[one.x - xinc][one.y - yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment && !is_horizontal)
                {
                    yinc += 1;
                    canvas[one.x - xinc][one.y - yinc] = "-";
                    xinc += 1;
                    shift_counter = 1;

                }
             
            }
            
        }

        //225 to 270
        if (abs(deltay) > abs(deltax))
        {
            shift_count = abs(deltax);
            vert_bar_count = abs(deltay) - shift_count;

            if (deltax == 0)
            {
                is_vertical = true;

            }
            else {
                shift_increment = abs(deltay / deltax);
                is_vertical = false;
            }

            int xinc = 0;
            int yinc = 1; 
            
            int shift_counter = 1;
            for (int i = 0; i < abs(deltay); i++)
            {
                if (shift_counter < shift_increment || is_vertical)
                {
                    canvas[one.x - xinc][one.y - yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment || is_vertical)
                {
                    xinc += 1;
                    canvas[one.x - xinc][one.y - yinc] = "|";
                    yinc += 1;
                    shift_counter = 1;

                }
               
            }
        }
        
    }

    //Quadrant 4
    if (deltax > 0 && deltay < 0)
    {
        
        // less than -45 degrees (270 to 315)
        if (abs(deltay) >= deltax)
        {
            shift_count = deltax;
            vert_bar_count = abs(deltay) - shift_count;
            shift_increment = abs(deltay / deltax);

            int xinc = 0;
            int yinc = 1;

            int shift_counter = 1;
            for (int i = 0; i < abs(deltay); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one.x + xinc][one.y - yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment)
                {
                    xinc += 1;
                    canvas[one.x + xinc][one.y - yinc] = "|";
                    yinc += 1;
                    shift_counter = 1;

                }
          
            }
        }

        //315 to 360
        if (deltax > abs(deltay))
        {
            shift_count = deltay;
            dash_count = abs(deltax - shift_count);
            shift_increment = abs(deltax / deltay);


            int xinc = 1;
            int yinc = 0;

            int shift_counter = 1;
            for (int i = 0; i < deltax; i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one.x + xinc][one.y - yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                else if (shift_counter >= shift_increment)
                {
                    yinc += 1;
                    canvas[one.x + xinc][one.y - yinc] = "-";
                    xinc += 1;
                    shift_counter = 1;

                }
           

            }
        }
    }

    
}
/*
cout << "shift count: " << shift_count << endl;
          
            cout << "dash coun: " << dash_count << endl;
            cout << "slash increment: " << shift_increment << endl;
            cout << "vert bar count: " << vert_bar_count << endl;
*/
 





int main()
{
    const float PI = 3.1415926535897932384626433832795;
    int sizex = 100;
    int sizey = 50;
    vector<vector<string>> canvas;
    initializeCanvas(canvas, sizex, sizey);
    
    Vertice point1 = Vertice(0, 0, 0);
    Vertice point2 = Vertice(10, 30, 0);
    connectVertices(point2, point1, canvas);
    printCanvas(canvas,sizex,sizey);
    /*
    Vertice transform = Vertice(2, 1, -10);
    //rotation in radians
    float r = 0;
    float scalar = 200;
    int height = 1;
    Cube cube = Cube(scalar, transform, height);
    
    for (int i = 0; i < cube.faces.size(); i++)
    {
        connectVertices(cube.faces[i][0], cube.faces[i][1], canvas);
        connectVertices(cube.faces[i][1], cube.faces[i][2], canvas);
        connectVertices(cube.faces[i][2], cube.faces[i][3], canvas);
        connectVertices(cube.faces[i][3], cube.faces[i][0], canvas);
    }

    printCanvas(canvas);
    
    int counter = 1;
    while (counter < 11)
    {
       
        
        r += .2;
        cube.rotate(r);
        //cout << endl << counter << endl;
        for (int i = 0; i < cube.faces.size(); i++)
        {
            connectVertices(cube.faces[i][0], cube.faces[i][1], canvas);
            //connectVertices(cube.faces[i][1], cube.faces[i][2], canvas);
            //connectVertices(cube.faces[i][2], cube.faces[i][3], canvas);
            //connectVertices(cube.faces[i][3], cube.faces[i][0], canvas);

            cout << "face 0: " << "x: " << cube.faces[i][0].x << "y: " << cube.faces[i][0].y << "z: "<< cube.faces[i][0].z << endl;
            cout << "face 1: " << "x: " << cube.faces[i][1].x << "y: " << cube.faces[i][1].y << "z: " << cube.faces[i][1].z << endl;
            //cout << "face 2: " << "x: " << cube.faces[i][2].x << "y: " << cube.faces[i][2].y << "z: " << cube.faces[i][2].z << endl;
            //cout << "face 3: " << "x: " << cube.faces[i][3].x << "y: " << cube.faces[i][3].y << "z: " << cube.faces[i][3].z << endl;
        }
        printCanvas(canvas);
        cout << "r: " << r << endl;
        
        resetCanvas(canvas);
        
        //cube.print();

        counter += 1;
        this_thread::sleep_for(chrono::duration<double>(.15));
        
    }
    */
}



