#include "polygon.hpp"

Polygon::Polygon(vector<Vertice> pvertices)
{
	vertices = pvertices;

}

void Polygon::printVerticesLocations()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << "Vertex " << i+1 << " X Position: " << vertices[i].getx() << endl;
		cout << "Vertex " << i+1 << " Y Position: " << vertices[i].gety() << endl;
		cout << "Vertex " << i+1 << " Z Position: " << vertices[i].gety() << endl << endl;
	}
}

