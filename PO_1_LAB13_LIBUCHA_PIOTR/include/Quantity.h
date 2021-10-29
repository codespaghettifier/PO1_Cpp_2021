#pragma once

#include <string>
#include <iostream>
#include <vector>

/// Klasa bazowa dla wszystkich klas pochodnych Quantity.
class QuantityBase
{
public:
	QuantityBase(std::string name);

	/// Wypisuje informacje o obiekcie na standardowe wyście.
	virtual void Print() const = 0;

	virtual ~QuantityBase();

protected:
	std::string _name;
};

/// Szablon klas reprezentujących pewną wielkość wraz z nazwą tej wielkości.
template<typename T>
class Quantity : public QuantityBase
{
public:
	Quantity(std::string name, T value);

	/// Ustawia nową wartość dla przechowywwanej wielkości. 
	inline void SetValue(T value);
	
	/// Wypisuje informacje o obiekcie na standardowe wyście.
	virtual void Print() const override;

	~Quantity();

protected:
	T _value;
};

using QuantityDouble = Quantity<double>;
using QuantityFloat = Quantity<float>;
using QuantityInt = Quantity<int>;
using QuantityChar = Quantity<char>;
using QuantityBool = Quantity<bool>;

template<typename T>
Quantity<T>::Quantity(std::string name, T value)
: QuantityBase(name)
, _value(value) {}

template<typename T>
inline void Quantity<T>::SetValue(T value)
{
	_value = value;
}

template<typename T>
void Quantity<T>::Print() const
{
	std::cout<<_name<<": "<<_value<<std::endl;
}

template<typename T>
Quantity<T>::~Quantity() {}


/// Szablon klas reprezentujących pewną wielkość wraz z nazwą tej wielkości oraz jednostką, w jakiej ta wartość została wyrażona.
template<typename T>
class QuantityWithUnits : public Quantity<T>
{
public:
	QuantityWithUnits(std::string name, T value, std::string units);

	/// Wypisuje informacje o obiekcie na standardowe wyście.
	virtual void Print() const override;

	~QuantityWithUnits();

private:
	std::string _units;
};

template<typename T>
QuantityWithUnits<T>::QuantityWithUnits(std::string name, T value, std::string units)
: Quantity<T>(name, value)
, _units(units) {}

template<typename T>
void QuantityWithUnits<T>::Print() const
{
	std::cout<<this->_name<<": "<<this->_value<<" ["<<_units<<"]"<<std::endl;
}

template<typename T>
QuantityWithUnits<T>::~QuantityWithUnits() {}

/// Klasa obiektów przechwujących zbiór wielkości w postaci obiektów klas dziedziczących po QuantityBase
class ArrayOfQuantities
{
public:
	ArrayOfQuantities(unsigned maxSize);

	/// Tworzy nowy obiekt klasy szablonowej Quanityty<T>, dodaje wzkażnik na ten obiekt do przechowywanego zbioru. Zwraca wzkaźnik na utworzony obiekt.
	template<typename T>
	Quantity<T>* CreateAndAdd(std::string name, T value);
	
	/// Wypisuje informacje o wszystkich obiektach ze zbioru na standardowe wyście.
	void Print() const;

	~ArrayOfQuantities();

private:
	unsigned _maxSize;
	std::vector<QuantityBase*> _quantities;
};

template<typename T>
Quantity<T>* ArrayOfQuantities::CreateAndAdd(std::string name, T value)
{
	Quantity<T>* newQuantity = new Quantity<T>(name, value);
	_quantities.push_back(newQuantity);
	return newQuantity;
}
