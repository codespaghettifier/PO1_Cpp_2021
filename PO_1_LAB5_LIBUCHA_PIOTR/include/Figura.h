#pragma once

#include "Wierzcholek.h"

#include <string>
#include <vector>

/// Klasa reprezenutjąca zbiór punktów o współrzędnych całkowitych
class Figura
{
public:
	Figura(std::string name);

	/** Metoda dodająca wierzchołek v do zbioru
	* @param v 
	* @return ten obiekt */

	Figura& operator+=(Wierzcholek v);
	/** Metoda dodająca wierzchołek v do zbioru
	* @param v 
	* @return ten obiekt */
	Figura& dodajW(Wierzcholek v);

	/** Metoda zwracająca nazwę tego obiektu
	* @return nazwa tego zbioru */
	std::string nazwa() const;

	bool operator==(const Figura& other) const;
	const Wierzcholek& getVertex(unsigned index) const;
	unsigned getSize() const;

protected:
	/// Nazwa zbioru
	std::string _name;
	/// Punkty w zbiorze
	std::vector<Wierzcholek> _vertices;
};

/** Operator wypisujący figurę figure na strumień stream i zwracający ten strumnień
* @param stream
* @param figure
* @return stream */
std::ostream& operator<<(std::ostream& stream, const Figura& figure);