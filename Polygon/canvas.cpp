#include "canvas.hpp"


Canvas::Canvas(int psizex, int psizey)
{
    sizex = psizex;
    sizey = psizey;
   
    canvas.resize(sizex);
    for (int x = 0; x < sizex; x++)
    {
        for (int y = 0; y < sizey;y++)
        {
            canvas[x].resize(sizey);
            canvas[x][y] = ".";
        }
    }
}

void Canvas::print()
{
    for (int y = 0; y < sizey; y++)
    {
        for (int x = 0; x < sizex;x++)
        {
            canvas[x][y] = ".";
            cout << canvas[x][y];
        }
        cout << endl;
    }
    //cout << "we have" << polygons.size() << "polygons";
}

