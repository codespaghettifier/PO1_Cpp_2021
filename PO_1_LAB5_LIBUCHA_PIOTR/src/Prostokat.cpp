#include "../include/Prostokat.h"

#include <iostream>

Prostokat::Prostokat(std::string name)
: Figura(name)
{
	std::cout<<"Tak naprawdę jestem prostokątem."<<std::endl;
}

float Prostokat::pole() const
{
	return _vertices[0].distanceTo(_vertices[1]) * _vertices[0].distanceTo(_vertices[3]);
}