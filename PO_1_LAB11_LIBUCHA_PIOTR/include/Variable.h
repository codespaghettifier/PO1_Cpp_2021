#pragma once

#include <string>
#include <iostream>
#include <vector>

class VariableBase
{
public:
	VariableBase(std::string name);

	virtual void Print() const = 0;

	virtual ~VariableBase();

protected:
	std::string _name;
};


template<typename T>
class Variable : public VariableBase
{
public:
	Variable(std::string name, T value);

	virtual void Print() const override;
	inline void SetValue(T value);

	~Variable();
protected:
	T _value;
};

template<typename T>
inline void Variable<T>::SetValue(T value)
{
	_value = value;
}

using VariableDouble = Variable<double>;
using VariableInt = Variable<int>;
using VariableFloat = Variable<float>;
using VariableChar = Variable<char>;
using VariableBool = Variable<bool>;

template<typename T>
Variable<T>::Variable(std::string name, T value)
: VariableBase(name)
, _value(value) {}

template<typename T>
void Variable<T>::Print() const
{
	std::cout<<_name<<": "<<_value<<std::endl;
}

template<typename T>
Variable<T>::~Variable() {}


template<typename T>
class VariableWithUnits : public Variable<T>
{
public:
	VariableWithUnits(std::string name, T value, std::string units);

	virtual void Print() const override;

	~VariableWithUnits();

private:
	std::string _units;
};

template<typename T>
VariableWithUnits<T>::VariableWithUnits(std::string name, T value, std::string units)
: Variable<T>(name, value)
, _units(units) {}

template<typename T>
void VariableWithUnits<T>::Print() const
{
	std::cout<<this->_name<<": "<<this->_value<<" ["<<_units<<"]"<<std::endl;
}

template<typename T>
VariableWithUnits<T>::~VariableWithUnits() {}


class ArrayOfVariables
{
public:
	ArrayOfVariables(unsigned maxSize);

	template<typename T>
	Variable<T>* CreateAndAdd(std::string name, T value);
	void Print() const;

	~ArrayOfVariables();

private:
	unsigned _maxSize;
	std::vector<VariableBase*> _variables;
};

template<typename T>
Variable<T>* ArrayOfVariables::CreateAndAdd(std::string name, T value)
{
	Variable<T>* var = new Variable<T>(name, value);
	_variables.push_back(var);
	return var;
}

