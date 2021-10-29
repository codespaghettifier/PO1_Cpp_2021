#include "../include/KontenerFigur.h"

void KontenerFigur::operator+=(Figura* figure)
{
	_figures.push_back(figure);
}

unsigned KontenerFigur::size() const
{
	return _figures.size();
}

Figura* KontenerFigur::operator[](unsigned index) const
{
	return _figures[index];
}

std::ostream& operator<<(std::ostream& stream, const KontenerFigur& container)
{
	for(unsigned a = 0; a < container.size(); a++)
	{
		stream<<*container[a];
	}
	return stream;
}