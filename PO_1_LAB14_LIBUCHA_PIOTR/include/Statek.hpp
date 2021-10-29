#pragma once

#include "Pozycja.hpp"

#include <vector>

namespace Statki
{

enum TypStatku
{
	CZTEROMASZTOWIEC = 1,
	TROJMASZTOWIEC = 2,
	DWUMASZTOWIEC = 3, 
	JEDNOMASZTOWIEC = 4
};

class Statek
{
public:
	Statek(TypStatku typ, Pozycja pozycja);

	TypStatku typ;
	std::vector<Pozycja> pozycje;
};

}