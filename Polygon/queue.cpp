#include "queue.hpp"



Queue::Queue(float sizex, float sizey, float angle)
{
	scale = 0;
    
    this->sizex = sizex;
    this->sizey = sizey;
    persAngle = angle;

    rotation = 0;

    persX = 0;
    persY = 0;
    persZ = 0;
    initializeCanvas();

    faces = {};
    

}

void Queue::initializeCanvas()
{
    //Offset of 1 to allow coordinates to reach up to the size (Can do 100 instead of only 99 when size is 100)
    canvas.resize(sizex+1);

    for (int y = 0; y < sizey+1; y++)
    {
        for (int x = 0; x < sizex+1;x++)
        {
            canvas[x].resize(sizey+1);
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

vector<int> Queue::convert2D(Vertice v)
{
    float tempx = sqrt(pow(v.x - persX, 2) + pow(v.z - persZ, 2)) * sin(atan((v.x - persX) / (v.z - persZ) + rotation));
    float tempy = v.y - persY;
    float tempz = sqrt(pow(v.x - persX, 2) + pow(v.z - persZ, 2)) * cos(atan((v.x - persX) / (v.z - persZ) + rotation));

    int newx = (tempx * sizex) / (2 * tan(persAngle / 2) * tempz);
    int newy = (tempy * sizey) / (2 * tan(persAngle / 2) * tempz);

    //cout << "X: " << newx << endl;
    //cout << "Y: " << newy << endl;
    //cout << "tempZ:    " << tempz << endl;
    return {newx, newy};
}

void Queue::connectVertices(vector<int> one, vector<int> two)
{

    //if on the same point
    if (one[0] == two[0] && one[1] == two[1])
    {
        return;
    }

    int deltax = two[0] - one[0];
    int deltay = two[1] - one[1];
    

    
    int dash_count = 0;
    int vert_bar_count = 0;

    int shift_count = 0;
    int shift_increment = 0;
    int shift_counter = 0;

    

    int halts;
    int halt_increment;
    int halt_counter = 0;

    bool is_horizontal = false;
    bool is_vertical = false;


    //Quadrant 1
    if (deltax >= 0 && deltay >= 0)
    {
        
        
        //less than 45 degrees (0 to 45)
        if (deltax >= deltay)
        {
            //cout << "mark";
            cout << "deltax: " << deltax << endl;
            cout << "deltay: " << deltay << endl;

            shift_count = deltay;
            dash_count = deltax - shift_count;
            if (deltay == 0)
            {
                is_horizontal = true;

            }
            else {
                shift_increment = deltax / deltay;

                halts = (deltax % deltay) / shift_increment;
                if (halts == 0)
                {
                    halt_increment = deltax;
                }
                else
                {
                    halt_increment = deltay / halts;
                }
                

                is_horizontal = false;
            }



            int xinc = 0;
            int yinc = 0;
            //shift_counter to mark when a slash should be entered
            


            for (int i = 0; i <= deltax; i++)
            {

                if (shift_counter < shift_increment || is_horizontal)
                {
                    canvas[one[0] + xinc][one[1] + yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;
                    if (shift_counter >= shift_increment && !is_horizontal)
                    {
                        if (halt_counter < halt_increment)
                        {
                            yinc += 1;
                            shift_counter = 0;
                            halt_counter += 1;
                        }
                        else
                        {
                            halt_counter = 0;
                            shift_counter = 0;
                        }
                    }

                }


            }
        }


        //greater than 45 degrees (45 to 90)
        if (deltay > deltax)
        {
            
            
            
            //cout << "mark";
            shift_count = deltax;
            vert_bar_count = deltay - shift_count;

            if (deltax == 0)
            {
                is_vertical = true;

            }
            else {
                shift_increment = deltay / deltax;

                halts = (deltay % deltax) / shift_increment;
                if (halts == 0)
                {
                    halt_increment = deltay;
                }
                else
                {
                    halt_increment = deltax / halts;
                }
                is_vertical = false;
            }
            
            
            int xinc = 0;
            int yinc = 0;
            
            for (int i = 0; i <= deltay; i++)
            {
                if (shift_counter < shift_increment || is_vertical)
                {
                    canvas[one[0] + xinc][one[1] + yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                    if (shift_counter >= shift_increment && !is_vertical)
                    {
                        if (halt_counter < halt_increment)
                        {
                            xinc += 1;
                            shift_counter = 0;
                            halt_counter += 1;
                        }
                        else
                        {
                            halt_counter = 0;
                            shift_counter = 0;
                        }
                        
                        
                    }

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

            halts = (abs(deltay) % abs(deltax)) / shift_increment;
            if (halts == 0)
            {
                halt_increment = abs(deltay);
            }
            else
            {
                halt_increment = abs(deltax) / halts;
            }




            int xinc = 0;
            int yinc = 0;

           
            for (int i = 0; i <= abs(deltay); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one[0] - xinc][one[1] + yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_horizontal)
                {
                    if (halt_counter < halt_increment)
                    {
                        xinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
                }

            }
            
        }

        //135 to 180
        if (abs(deltax) > deltay)
        {
            shift_count = deltay;
            dash_count = abs(deltax - shift_count);
            shift_increment = abs(deltax / deltay);

            halts = (abs(deltax) % abs(deltay)) / shift_increment;
            if (halts == 0)
            {
                halt_increment = abs(deltax);
            }
            else
            {
                halt_increment = abs(deltay) / halts;
            }


            int xinc = 0;
            int yinc = 0;

            
            for (int i = 0; i <= abs(deltax); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one[0] - xinc][one[1] + yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_horizontal)
                {
                    if (halt_counter < halt_increment)
                    {
                        yinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
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

                halts = (abs(deltax) % abs(deltay)) / shift_increment;
                if (halts == 0)
                {
                    halt_increment = abs(deltax);
                }
                else
                {
                    halt_increment = abs(deltay) / halts;
                }

                is_horizontal = false;
            }

            int xinc = 0;
            int yinc = 0;

            
            for (int i = 0; i <= abs(deltax); i++)
            {

                if (shift_counter < shift_increment || is_horizontal)
                {
                    canvas[one[0] - xinc][one[1] - yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_horizontal)
                {
                    if (halt_counter < halt_increment)
                    {
                        yinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
                }

            }

        }

        //225 to 270
        if (abs(deltay) > abs(deltax))
        { 
            //cout << "mark";
            shift_count = abs(deltax);
            vert_bar_count = abs(deltay) - shift_count;

            if (deltax == 0)
            {
                is_vertical = true;

            }
            else {
                shift_increment = abs(deltay / deltax);

                halts = (abs(deltay) % abs(deltax)) / shift_increment;
                if (halts == 0)
                {
                    halt_increment = abs(deltay);
                }
                else
                {
                    halt_increment = abs(deltax) / halts;
                }

                is_vertical = false;
            }

            int xinc = 0;
            int yinc = 0;

            for (int i = 0; i <= abs(deltay); i++)
            {
                if (shift_counter < shift_increment || is_vertical)
                {
                    canvas[one[0] - xinc][one[1] - yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_vertical)
                {
                    if (halt_counter < halt_increment)
                    {
                        xinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
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

            halts = (abs(deltay) % abs(deltax)) / shift_increment;
            if (halts == 0)
            {
                halt_increment = abs(deltay);
            }
            else
            {
                halt_increment = abs(deltax) / halts;
            }

            int xinc = 0;
            int yinc = 0;

            
            for (int i = 0; i <= abs(deltay); i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one[0] + xinc][one[1] - yinc] = "|";

                    yinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_horizontal)
                {
                    if (halt_counter < halt_increment)
                    {
                        xinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
                }

            }
        }

        //315 to 360
        if (deltax > abs(deltay))
        {
            shift_count = deltay;
            dash_count = abs(deltax - shift_count);
            shift_increment = abs(deltax / deltay);

            halts = (abs(deltax) % abs(deltay)) / shift_increment;
            if (halts == 0)
            {
                halt_increment = abs(deltax);
            }
            else
            {
                halt_increment = abs(deltay) / halts;
            }


            int xinc = 0;
            int yinc = 0;

            
            for (int i = 0; i <= deltax; i++)
            {
                if (shift_counter < shift_increment)
                {
                    canvas[one[0] + xinc][one[1] - yinc] = "-";

                    xinc += 1;
                    shift_counter += 1;

                }
                if (shift_counter >= shift_increment && !is_horizontal)
                {
                    if (halt_counter < halt_increment)
                    {
                        yinc += 1;
                        shift_counter = 0;
                        halt_counter += 1;
                    }
                    else
                    {
                        halt_counter = 0;
                        shift_counter = 0;
                    }
                }


            }
        }
    }
    canvas[one[0]][one[1]] = "X";
    canvas[two[0]][two[1]] = "X";
}

void Queue::run()
{
    for (int i = 0; i < faces.size(); i++)
    {
        connectVertices(convert2D(faces[i][faces[i].size()-1]), convert2D(faces[i][0]));
        for (int k = 0; k < faces[i].size()-1; k++)
        {
            connectVertices(convert2D(faces[i][k]), convert2D(faces[i][k + 1]));
        }
    }
    printCanvas();
    resetCanvas();
}

void Queue::addToQueue(vector<Vertice> v)
{
    faces.push_back(v);
}

