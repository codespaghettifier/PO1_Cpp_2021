#pragma once

#include "RangeArray.h"

/// Szablon klasy przechowującej tablicę liczb typu drugiej liczby z pary z obietku PairOfNumbers przekazanego w konstruktorze. Rozmiar tablicy to różnica watości liczb w parze (druga - pierwsza).
template<typename T>
class RangeArray
{
public:
	RangeArray(const PairOfNumbers<int, T>& pair)
	{
		_size = pair.second - pair.first;
		_array = new T[_size];
	}

	RangeArray(const RangeArray& other)
	: _size(other._size)
	, _array(new T[_size])
	{
		for(unsigned a = 0; a < _size; a++)
		{
			_array[a] = other._array[a];
		}
	}

	/// Zwraca rozmiar tablicy
	unsigned Size() const
	{
		return _size;
	}

	/// Zwraca referencję na obiekt tablicy o danym indeksie. Indeksy ujemne są liczone od końca talicy (jak w Pythonie).
	T& operator[](int index)
	{
		index = index < 0 ? _size + index : index;

		return _array[index];
	}

	/// Zwraca referencję na obiekt tablicy o danym indeksie. Indeksy ujemne są liczone od końca talicy (jak w Pythonie).
	T& At(int index)
	{
		return (*this)[index];
	}

	~RangeArray()
	{
		delete[] _array;
	}
private:
	unsigned _size;
	T* _array;
};