#include "../include/Product.h"

#include <iostream>

Product::Product(Primitive& primA, Primitive& primB)
: _primA(primA)
, _primB(primB) {}

float Product::getValue() const
{
	return _primA.getValue() * _primB.getValue();
}

void Product::print() const
{
	std::cout<<"(";
	_primA.print();
	std::cout<<"*";
	_primB.print();
	std::cout<<")";
}
