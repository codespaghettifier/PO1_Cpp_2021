#include "../include/V.h"

#include <utility>
#include <iostream>
#include <cmath>

V::V(unsigned size)
: _size(size)
{
	_values = new double[_size];
	for(unsigned a = 0; a < _size; a++)
	{
		_values[a] = 0;
	}
}

V::V(const V& other)
: _size(other._size)
{
	_values = new double[_size];
	for(unsigned a = 0; a < _size; a++)
	{
		_values[a] = other._values[a];
	}
}

V::V(V&& other)
: _size(std::exchange(other._size, 0))
, _values(std::exchange(other._values, nullptr)) {}

double& V::at(unsigned index) const
{
	return _values[index];
}

void V::print(std::string str) const
{
	std::cout<<str<<"(";
	if(_size) std::cout<<_values[0];
	for(unsigned a = 1; a < _size; a++)
	{
		std::cout<<", "<<_values[a];
	}
	std::cout<<")"<<std::endl;
}

double V::dot(const V& v1, const V& v2)
{
	if(v1._size != v2._size)
	{
		std::cout<<"Error, vectors of different dimensions!"<<std::endl;
		return 0;
	}

	double sum = 0;
	for(unsigned a = 0; a < v1._size; a++)
	{
		sum += v1._values[a] * v2._values[a];
	}
	return sum;
}

V::operator double() const
{
	return norm();
}

double V::norm() const
{
	double sum = 0;
	for(unsigned a = 0; a < _size; a++)
	{
		sum += _values[a] * _values[a];
	}
	return sqrt(sum);
}

V V::sum(const V& v1, const V& v2)
{
	V s = v1;
	for(unsigned a = 0; a < s._size; a++)
	{
		s.at(a) += v2.at(a);
	}
	return s;
}

V V::sum(const V& v1, double number)
{
	V s = v1;
	for(unsigned a = 0; a < s._size; a++)
	{
		s.at(a) += number;
	}
	return s;
}

V::~V()
{
	if(_size)
	{
		_size = 0;
		delete[] _values;
		_values = nullptr;
	}
}