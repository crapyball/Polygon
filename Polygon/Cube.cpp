#include "cube.hpp"
#include "vertice.hpp"


Cube::Cube(int scalar, Vertice transform, int height)
{	
	r = 0;
	this->height = height;
	this->transform = Vertice(transform.x,transform.y, transform.z);
	this->scalar = scalar;
	faces = {
		vector<Vertice> {Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0), Vertice(E(-cos(r), height, -sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0],E(sin(r), height, -cos(r))[1], 0), Vertice(E(cos(r), height, sin(r))[0],E(cos(r), height, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0],E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0],E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), height,-sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0], E(sin(r), height, -cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), height, sin(r))[0], E(cos(r), height, sin(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0], E(sin(r), height, -cos(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), height, sin(r))[0], E(cos(r), height, sin(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(-cos(r), height, -sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0)  }

	};
	
}

vector<int> Cube::E(float x, float y, float z)
{
	
	return vector<int> {int(((x + transform.x)* scalar) / (z - transform.z)), int(((y + transform.y)* scalar) / (z - transform.z)) };
	//returns x and y coords
}

vector<vector<Vertice>> Cube::rotate(float rotation)
{
	r = rotation;

	faces = {
		vector<Vertice> {Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0), Vertice(E(-cos(r), height, -sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0],E(sin(r), height, -cos(r))[1], 0), Vertice(E(cos(r), height, sin(r))[0],E(cos(r), height, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0],E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0],E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), height,-sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0], E(sin(r), height, -cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), height, sin(r))[0], E(cos(r), height, sin(r))[1], 0), Vertice(E(sin(r), height, -cos(r))[0], E(sin(r), height, -cos(r))[1], 0), Vertice(E(sin(r), 0, -cos(r))[0], E(sin(r), 0, -cos(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0)},
		vector<Vertice> {Vertice(E(cos(r), height, sin(r))[0], E(cos(r), height, sin(r))[1], 0), Vertice(E(cos(r), 0, sin(r))[0], E(cos(r), 0, sin(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0), Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0)},
		vector<Vertice> {Vertice(E(-cos(r), 0, -sin(r))[0], E(-cos(r), 0, -sin(r))[1], 0), Vertice(E(-cos(r), height, -sin(r))[0], E(-cos(r), height, -sin(r))[1], 0), Vertice(E(-sin(r), height, cos(r))[0], E(-sin(r), height, cos(r))[1], 0), Vertice(E(-sin(r), 0, cos(r))[0], E(-sin(r), 0, cos(r))[1], 0)  }

	};

	return faces;

}

void Cube::print()
{
	for (int i = 0; i < faces.size(); i++)
	{
		for (int k = 0; k < faces[0].size(); k++)
		{
			cout << "Face" << i + 1 << "/" << "point" << k + 1 << ": " << "x: " << faces[i][k].x << " y: " << faces[i][k].y << endl;
 		}
	}
}