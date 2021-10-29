#include "../include/Sum.h"

Sum sumData(const Data& data)
{
	float sum = 0;
	const std::vector<float>& numbers = data.getNumbers();
	std::for_each(numbers.begin(), numbers.end(), [&sum](float number){sum += number;});
	return Sum(sum);
}

Sum::Sum(float sum)
: _sum{sum} {}

float Sum::value() const
{
	return _sum;
}

void Sum::operator()(float number)
{
	_sum += number;
}