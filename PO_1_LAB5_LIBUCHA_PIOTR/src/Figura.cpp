#include "../include/Figura.h"

#include <iostream>

Figura::Figura(std::string name)
: _name(name)
{
	std::cout<<"Jestem nową figurą "<<_name<<std::endl;
}

Figura& Figura::operator+=(Wierzcholek v)
{
	_vertices.push_back(v);
	return *this;
}

Figura& Figura::dodajW(Wierzcholek v)
{
	return *this += v;
}

std::string Figura::nazwa() const
{
	return _name;
}

bool Figura::operator==(const Figura& other) const
{
	if(this == &other) return true;

	if(_vertices.size() != other._vertices.size()) return false;

	for(unsigned a = 0; a < _vertices.size(); a++)
	{
		if(_vertices[a] != other._vertices[a]) return false;
	}
	return true;
}

const Wierzcholek& Figura::getVertex(unsigned index) const
{
	return _vertices[index];
}

unsigned Figura::getSize() const
{
	return _vertices.size();
}

std::ostream& operator<<(std::ostream& stream, const Figura& figure)
{
	stream<<"Figura "<<figure.nazwa()<<":\n";
	for(unsigned a = 0; a < figure.getSize(); a++)
	{
		stream<<figure.getVertex(a);
	}
	return stream<<"\n";
}