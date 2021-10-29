#pragma once

#include <sstream>

/// Klasa reprezentująca punkt o całkowitych współrzędnych
class Wierzcholek
{
public:
	Wierzcholek(int x, int y);
	inline int getX() const;
	inline int getY() const;

	bool operator==(const Wierzcholek& other) const;
	bool operator!=(const Wierzcholek& other) const;

	/** Metoda zwracająca odległość między tym punktem, a punktem other
	* @param other
	* @return odległość między tym punktem, a punktem other */
	float distanceTo(const Wierzcholek& other) const;

private:
	/// Współrzedna x punktu
	int _x;
	/// Współrzedna y punktu
	int _y;
};

int Wierzcholek::getX() const
{
	return _x;
}

int Wierzcholek::getY() const
{
	return _y;
}

/** Operator wypisujący wierzchołek v na strumień stream i zwracający ten strumnień
* @param stream
* @param v 
* @return stream */
std::ostream& operator<<(std::ostream& stream, const Wierzcholek& v);