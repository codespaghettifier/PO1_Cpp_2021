#pragma once

#include "Figura.h"

///Klasa reprezentująca prostokąt
class Prostokat : public Figura
{
public:
	Prostokat(std::string name);

	/** Metoda zwracająca pole prostokąta
	* @return pole prostokąta*/
	float pole() const;
};