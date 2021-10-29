#pragma once

#include <cmath>
#include <functional>

///Funkcjonał. Zwraca wartość wyrażenia sin(ax + b)
class Sinus
{
public:
	Sinus(double a, double b);

	/** Operator wywołania, zwraca wartość wyrażenia sin(_a * x + b)
	* @param x 
	* @return sin(_a * x + b)
	*/
	double operator()(double x) const;

private:
	double _a;
	double _b;
};

///Funkcjonał. Zwraca wartość wyrażenia sqrt(x)
class PierwiastekKwadratowy
{
public:

	/** Operator wywołania, zwraca wartość wyrażenia sqrt(x)
	* @param x 
	* @return sqrt(x)
	*/
	double operator()(double x) const;
};

///Funkcjonał. Zwraca wartość wyrażenia ax + b
class Liniowa
{
public:
	Liniowa(double a, double b);

	/** Operator wywołania, zwraca wartość wyrażenia _a * x + b
	* @param x 
	* @return _a * x + b
	*/
	double operator()(double x) const;

private:
	double _a;
	double _b;
};