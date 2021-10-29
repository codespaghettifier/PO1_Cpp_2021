#pragma once

#include "Data.h"

/// Reprezentuje sumę liczb.
class Sum
{
public:
	Sum(float sum);
	//Sum(const Data& data);

	/// Zwraca wartość sumy wszystkich dodanych liczb
	float value() const;
	
	/// Dodaje liczbę number do przechowywanej sumy
	void operator()(float number);

private:
	float _sum;
};

Sum sumData(const Data& data);