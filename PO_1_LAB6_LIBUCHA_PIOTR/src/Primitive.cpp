#include "../include/Primitive.h"

#include <iostream>

Primitive::Primitive(float value)
: _value(value) {}

float Primitive::getValue() const
{
	return _value;
}

void Primitive::print() const
{
	std::cout<<_value;
}

void Primitive::PrintWithValue() const
{
	print();
	std::cout<<" = "<<getValue()<<std::endl;
}

void Primitive::Set(float value)
{
	_value = value;
}

Primitive::~Primitive()
{}