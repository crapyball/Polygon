#include "queue.hpp"



Queue::Queue(int x, int y)
{
	scale = 0;
    sizex = x;
    sizey = y;
    initializeCanvas();

}

void Queue::initializeCanvas()
{
    //Offset of 1 to allow coordinates to reach up to the size (Can do 100 instead of only 99 when size is 100)
    sizex += 1;
    sizey += 1;

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

void Queue::resetCanvas()
{
    for (int y = 0; y < canvas[0].size(); y++)
    {
        for (int x = 0; x < canvas.size();x++)
        {
            canvas[x][y] = " ";
        }
    }
}

void Queue::printCanvas()
{

    std::string out;
    out.reserve((sizex + 3) * (sizey + 2));

    std::string border(sizex + 2, '-');
    out += border + '\n';

    for (int y = canvas[0].size() - 1; y >= 0; y--) {
        out += '|';
        for (int x = 0; x < canvas.size(); x++) {
            out += canvas[x][y];
        }
        out += "|\n";
    }

    out += border;

    std::cout << out;
}

void Queue::setScale(float s)
{
    scale = s;
}