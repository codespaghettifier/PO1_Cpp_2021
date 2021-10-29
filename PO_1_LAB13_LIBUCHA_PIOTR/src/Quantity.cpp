#include "../include/Quantity.h"

QuantityBase::QuantityBase(std::string name)
: _name(name) {}

QuantityBase::~QuantityBase() {}


ArrayOfQuantities::ArrayOfQuantities(unsigned maxSize)
: _maxSize(maxSize) {}

void ArrayOfQuantities::Print() const
{
	for(unsigned a = 0; a < _quantities.size(); a++)
	{
		_quantities[a]->Print();
	}
}

ArrayOfQuantities::~ArrayOfQuantities()
{
	for(unsigned a = 0; a < _quantities.size(); a++)
	{
		delete _quantities[a];
	}
}