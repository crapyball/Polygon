#include "vertice.hpp"

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