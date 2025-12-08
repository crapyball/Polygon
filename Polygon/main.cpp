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
#include "queue.hpp"
using namespace std;


int main()
{
    const float PI = 3.1415926535897932384626433832795;
    float widthx = 200;
    float heighty = 200;
    float angle = 2 * PI / 3;
    
    Vertice point1 = Vertice(400, 400, 300);
    Vertice point2 = Vertice(600, 400, 300);
    Vertice point3 = Vertice(600, 600, 300);
    Vertice point4 = Vertice(400, 600, 300);

    Queue queue = Queue(widthx, heighty, angle);
    vector<Vertice> face1 = { Vertice(400, 400, 300), Vertice(600, 400, 300), Vertice(600, 600, 300), Vertice(400, 600, 300) };
    queue.addToQueue(face1);


    //this_thread::sleep_for(chrono::duration<double>(.15));
    queue.run();
    
    
    while (true)
    {
        char input;
        cin >> input;
        if (input == 'w')
        {
            queue.persZ += 20; 
        }
        if (input == 's')
        {
            queue.persZ -= 20;
        }
        if (input == 'd')
        {
            queue.persX += 20;
        }
        if (input == 'a')
        {
            queue.persX -= 20;
        }
        //cout << "Z: " << queue.persZ;
        
        queue.run();
    }
    
    
    
    
}



