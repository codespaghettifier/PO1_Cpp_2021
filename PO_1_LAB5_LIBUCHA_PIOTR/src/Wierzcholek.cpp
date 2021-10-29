#include "../include/Wierzcholek.h"

#include <math.h>

Wierzcholek::Wierzcholek(int x, int y)
: _x(x)
, _y(y) {}

bool Wierzcholek::operator==(const Wierzcholek& other) const
{
	if(this == &other) return true;
	
	return _x == other._x && _y == other._y;
}

bool Wierzcholek::operator!=(const Wierzcholek& other) const
{
	return !(*this == other);
}

float Wierzcholek::distanceTo(const Wierzcholek& other) const
{
	return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
}

std::ostream& operator<<(std::ostream& stream, const Wierzcholek& v)
{
	return stream<<" ("<<v.getX()<<", "<<v.getY()<<")";
}