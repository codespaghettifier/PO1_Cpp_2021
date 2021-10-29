#include "../include/Ratio.h"

#include <iostream>

Ratio::Ratio(Primitive& primA, Primitive& primB)
: _primA(primA)
, _primB(primB) {}

float Ratio::getValue() const
{
	return _primA.getValue() / _primB.getValue();
}

void Ratio::print() const
{
	std::cout<<"(";
	_primA.print();
	std::cout<<"/";
	_primB.print();
	std::cout<<")";
}
