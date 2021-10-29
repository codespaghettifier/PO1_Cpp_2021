#include "../include/ZlozenieFunkcji.h"

void ZlozenieFunkcji::insert(std::function<double(double)> function)
{
	_functions.push_back(function);
}

double ZlozenieFunkcji::wynik(double x)
{
	_results.clear();
	_results.push_back(_functions[0](x));	//Zakładam, że funkcja nie będzie wywoływana, przed dodatniem funkcji do złożenia
	for(unsigned a = 1; a < _functions.size(); a++)
	{
		_results.push_back(_functions[a](_results[a - 1]));
	}
	return _results[_results.size() - 1];
}

double ZlozenieFunkcji::operator[](unsigned index)
{
	return _results[index];
}