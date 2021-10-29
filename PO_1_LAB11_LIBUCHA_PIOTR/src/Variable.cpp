#include "../include/Variable.h"

VariableBase::VariableBase(std::string name)
: _name(name) {}

VariableBase::~VariableBase() {}


ArrayOfVariables::ArrayOfVariables(unsigned maxSize)
: _maxSize(maxSize) {}

void ArrayOfVariables::Print() const
{
	for(VariableBase* var : _variables)
	{
		var->Print();
	}
}

ArrayOfVariables::~ArrayOfVariables()
{
	for(VariableBase* var : _variables)
	{
		delete var;
	}
}