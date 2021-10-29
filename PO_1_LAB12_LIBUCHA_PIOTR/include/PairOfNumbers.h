#pragma once

#include <iostream>

/// Szablon klasy reprezentującej parę liczb.
template<typename T1, typename T2>
class PairOfNumbers
{
public:
	T1& first;
	T2& second;

	PairOfNumbers(T1& first, T2& second)
	: first(first)
	, second(second) {}

	/// Tworzy nową parę z liczbami w odwróconej kolejności.
	PairOfNumbers<T2, T1> Swapped() const
	{
		return PairOfNumbers<T2, T1>(second, first);
	}

	/// Wypisuje parę liczba na standardowe wyjście.
	void Print() const
	{
		std::cout<<"Print method: "<<first<<" "<<second<<std::endl;
	}

	/// Dodaje wartość value do każdej z liczb w parze
	void Add(T1 value)
	{
		first += value;
		second += value; 
	}

	/// Dodaje wartość value do każdej z liczb w parze
	void Add(T2 value)
	{
		first += value;
		second += value; 
	}

	/// Mnoży wartość każdej z liczb w parze przez wartość value
	void Scale(T1 value)
	{
		first *= value;
		second *= value; 
	}

	/// Mnoży wartość każdej z liczb w parze przez wartość value
	void Scale(T2 value)
	{
		first *= value;
		second *= value; 
	}

	/// Wypisuje informację o tym, obiekt jest NON-const. Funkcja jest wywoływana (implicite) na obiektach NON-const. Jeżeli obiekt jest const, to zostaje wywołana funkcja void Info() const.
	void Info()
	{
		std::cout<<"This is NON-const pair of numbers"<<std::endl;
	}

	/// Wypisuje informację o tym, obiekt jest const. Funkcja jest wywoływana (implicite) na obiektach const. Jeżeli obiekt jest NON-const, to zostaje wywołana funkcja void Info().
	void Info() const
	{
		std::cout<<"This is const pair of numbers"<<std::endl;
	}
};

