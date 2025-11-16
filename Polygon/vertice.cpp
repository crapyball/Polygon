#include "vertice.hpp"

Vertice::Vertice()
{
	x = 0;
	y = 0;
	z = 0;
}
Vertice::Vertice(int px, int py, int pz)
{
	x = px;
	y = py;
	z = pz;
}
int Vertice::getx()
{
	return x;
}
int Vertice::gety()
{
	return y;
}
int Vertice::getz()
{
	return z;
}