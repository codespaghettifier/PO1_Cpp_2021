#pragma once

#include "Figura.h"

/// Kontener na obiekty Figura
class KontenerFigur
{
public:
	void operator+=(Figura* figure);
	/// Zwraca ilość obiektów Figura w zbiorze
	unsigned size() const;
	/// Zwraca figurę o indeksie index
	Figura* operator[](unsigned index) const;

private:
	/// Zbiór obietków klasy Figura
	std::vector<Figura*> _figures;
};

/** Operator wypisujący figury w kontenerze container na strumień stream i zwracający ten strumnień
* @param stream
* @param container
* @return stream */
std::ostream& operator<<(std::ostream& stream, const KontenerFigur& container);