#include "polygon.hpp"

Polygon::Polygon(vector<Vertice> pface1)
{
	face1 = pface1;

}

void Polygon::printface1Locations()
{
	for (int i = 0; i < face1.size(); i++)
	{
		cout << "Vertex " << i+1 << " X Position: " << face1[i].getx() << endl;
		cout << "Vertex " << i+1 << " Y Position: " << face1[i].gety() << endl;
		cout << "Vertex " << i+1 << " Z Position: " << face1[i].gety() << endl << endl;
	}
}

