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
    
    

    Queue queue = Queue(widthx, heighty, angle);

    vector<Vertice> face1 = { Vertice(200, 200, 300), Vertice(400, 200, 300), Vertice(400, 400, 300), Vertice(200, 400, 300) };
    vector<Vertice> face2 = { Vertice(200, 200, 700), Vertice(400, 200, 700), Vertice(400, 400, 700), Vertice(200, 400, 700) };

    vector<Vertice> face3 = { Vertice(200, 200, 300), Vertice(200, 400, 300), Vertice(200, 400, 700), Vertice(200, 200, 700) };
    //vector<Vertice> face3 = { Vertice(200, 200, 700), Vertice(200, 400, 700), Vertice(200, 400, 300), Vertice(200, 200, 300) };

    vector<Vertice> face4 = { Vertice(400, 200, 300), Vertice(400, 400, 300), Vertice(400, 400, 700), Vertice(400, 200, 700) };

    vector<Vertice> face5 = { Vertice(200, 200, 300), Vertice(400, 200, 300), Vertice(400, 200, 700), Vertice(200, 200, 700) };
    vector<Vertice> face6 = { Vertice(200, 400, 300), Vertice(400, 400, 300), Vertice(400, 400, 700), Vertice(200, 400, 700) };
    queue.addToQueue(face1);
    queue.addToQueue(face2);
    queue.addToQueue(face3);
    queue.addToQueue(face4);
    queue.addToQueue(face5);
    queue.addToQueue(face6);

    //vector<Vertice> test = { Vertice(40, 8, 70), Vertice(200, 200, 300)};
    //queue.addToQueue(test);
    //queue.connectVertices(queue.convert2D(test[0]), queue.convert2D(test[1]));
    //queue.printCanvas();
    //this_thread::sleep_for(chrono::duration<double>(.15));
    queue.run();
    //cout << queue.convert2D(test[1])[0] << endl;
    //cout << queue.convert2D(test[1])[1];
    //queue.connectVertices(queue.convert2D(test[0]), queue.convert2D(test[1]));
    //queue.printCanvas();
    while (true)
    {
        char input;
        cin >> input;
        if (input == 'w')
        {
            queue.persZ += 30; 
        }
        if (input == 's')
        {
            queue.persZ -= 30;
        }
        if (input == 'd')
        {
            queue.persX += 30;
        }
        if (input == 'a')
        {
            queue.persX -= 30;
        }
        if (input == 'e')
        {
            queue.persY += 30;
        }
        if (input == 'q')
        {
            queue.persY -= 30;
        }
        //cout << "Z: " << queue.persZ;
        
        queue.run();
    }
    
    
    
    
}



