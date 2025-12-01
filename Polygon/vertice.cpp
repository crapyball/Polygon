#include "vertice.hpp"

Vertice::Vertice()
{
	x = 0;
	y = 0;
	z = 0;
}
Vertice::Vertice(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}
float Vertice::getx()
{
	return x;
}
float Vertice::gety()
{
	return y;
}
float Vertice::getz()
{
	return z;
}