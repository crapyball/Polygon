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
    //if on the same point
    if (one.x == two.x && one.y == two.y)
    {
        cout << "same";
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

            cout << "upslash count: " << shift_count << endl;

            cout << "dash coun: " << dash_count << endl;
            cout << "slash increment: " << shift_increment << endl;
            cout << "vert bar count: " << vert_bar_count << endl;

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
    int sizex = 100;
    int sizey = 50;
    vector<vector<string>> canvas;
    initializeCanvas(canvas, sizex, sizey);
    

    Polygon face1 = Polygon(vector<Vertice> {Vertice(30, 20, 0), Vertice(60, 20, 0), Vertice(60, 35, 0), Vertice(30,35,0) });
    connect2Vertices(face1.vertices[0], face1.vertices[1], canvas);
    connect2Vertices(face1.vertices[1], face1.vertices[2], canvas);
    connect2Vertices(face1.vertices[2], face1.vertices[3], canvas);
    connect2Vertices(face1.vertices[3], face1.vertices[0], canvas);
    printCanvas(canvas, sizex, sizey);
}



