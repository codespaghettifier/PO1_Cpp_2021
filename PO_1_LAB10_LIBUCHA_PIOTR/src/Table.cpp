#include "../include/Table.h"

void Table::operator+=(Data data)
{
	_data.push_back(data);
	minRow = minRow < data.getNumbers().size() ? minRow : data.getNumbers().size();
}

const Table& Table::sortBy(std::function<bool(const Data& a, const Data& b)> compare)
{
	std::sort(_data.begin(), _data.end(), compare);
	return *this;
}

const Table& Table::sort(unsigned column)
{
	if(minRow <= column)
	{
		std::cout<<"Indeks 3 nieprawidlowy!"<<std::endl;
		return *this;
	}

	return sortBy([column](const Data& a, const Data& b){return a.getNumbers()[column] < b.getNumbers()[column];});
}

void Table::print() const
{
	std::for_each(_data.begin(), _data.end(), [](const Data& data){data.print();});
	std::cout<<std::endl;
}