#include "../include/Data.h"

Data::Data(std::string day, std::vector<float> numbers)
: _day(day)
, _numbers(numbers) {}

void Data::print() const
{
	std::cout<<_day<<":\t";
	std::for_each(_numbers.begin(), _numbers.end(), [](float number){std::cout<<std::setw(6)<<number;});
	std::cout<<std::endl;
}