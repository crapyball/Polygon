#include "Cube.hpp"
#include "vertice.hpp"


Cube::Cube(int scalar, Vertice transform, int height)
{	
	r = 0;
	this->height = height;
	this->transform = Vertice(transform.x,transform.y, transform.z);
	faces = {
		vector<Vertice> {Vertice(E(-sin(r), 2, cos(r))[0], E(-sin(r), 2, cos(r))[1], 0), Vertice(E(-cos(r), 2, -sin(r))[0], E(-cos(r), 2, -sin(r))[1], 0), Vertice(E(sin(r), 2, -cos(r))[0],E(sin(r), 2, -cos(r))[1], 0), Vertice(E(cos(r), 2, sin(r))[0],E(cos(r), 2, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0],E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0],E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), 2,-sin(r))[0], E(-cos(r), 2, -sin(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(sin(r), 2, -cos(r))[0], E(sin(r), 2, -cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), 2, sin(r))[0], E(cos(r), 2, sin(r))[1], 0), Vertice(E(sin(r), 2, -cos(r))[0], E(sin(r), 2, -cos(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), 2, sin(r))[0], E(cos(r), 2, sin(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-sin(r), 2, cos(r))[0], E(-sin(r), 2, cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(-cos(r), 2, -sin(r))[0], E(-cos(r), 2, -sin(r))[1], 0), Vertice(E(-sin(r), 2, cos(r))[0], E(-sin(r), 2, cos(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0)  }

	};
	

}

vector<int> Cube::E(int x, int y, int z)
{

	return vector<int> {int(((x + transform.x)* scalar) / (z - transform.z)), int(((y + transform.y)* scalar) / (z - transform.z)) };
	//returns x and y coords
}

