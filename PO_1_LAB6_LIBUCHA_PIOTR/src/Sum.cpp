#include "../include/Sum.h"

#include <iostream>

Sum::Sum(Primitive& primA, Primitive& primB)
: _primA(primA)
, _primB(primB) {}

float Sum::getValue() const
{
	return _primA.getValue() + _primB.getValue();
}

void Sum::print() const
{
	std::cout<<"(";
	_primA.print();
	std::cout<<"+";
	_primB.print();
	std::cout<<")";
}