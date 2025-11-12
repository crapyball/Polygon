#include "polygon.hpp"

Polygon::Polygon(int pnumvertices, vector<Vertice> pvertices)
{
	numvertices = pnumvertices;
	vertices = pvertices;

}

void Polygon::printVerticesLocations()
{
	for (int i = 0; i < numvertices; i++)
	{
		cout << "Vertex " << i+1 << " X Position: " << vertices[i].getx() << endl;
		cout << "Vertex " << i+1 << " Y Position: " << vertices[i].gety() << endl;
		cout << "Vertex " << i+1 << " Z Position: " << vertices[i].gety() << endl << endl;
		

	}
}