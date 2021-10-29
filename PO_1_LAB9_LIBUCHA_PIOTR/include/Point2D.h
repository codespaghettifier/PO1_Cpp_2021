#pragma once

#include <iostream>

/// Klasa reprezentująca dwuwymiarowy punkt o dyskretnych współrzędnych.
class Point2D
{
public:
	Point2D(int x, int y);

	/** Operator porównania z innym punktem Punkt2D
	* @param other inny punkt Point2D
	* @return zwraca prawdę jeżeli odległość od środka układu współrzędnych jest mniejsza niż odległość od środka układu współrzędnych punktu other
	*/
	bool operator<(const Point2D& other) const;

	/// Wypisuje punkt na standardowe wyjście
	void Print() const;

	/** Wypisuje punkt point na standardowe wyjście
	* @param point
	*/
	static void PrintPoint(const Point2D point);

	/** Wypisuje współrzędną y punktu point na standardowe wyjście
	* @param point
	*/
	static void FunctionPrintY(const Point2D& point);
	inline int getX() const;
	inline int getY() const;

private:
	int _x;
	int _y;
	/// Odległość od środka układu współrzędnych
	float _distanceToOrigin;
};

inline int Point2D::getX() const
{
	return _x;
}

inline int Point2D::getY() const
{
	return _y;
}

/** Funkcja porównująca dwa punkty Point2D
*	@param pointA
* 	@param pointB
*	@return zwraca prawdę jeżeli największa wspołrzędna pointA jest mniejsza niż najwięsza wspołrzędna pointB
*/
bool MaxDistanceAsc(const Point2D& pointA, const Point2D& pointB);

/// Funktor służący do sortowania punktów Point2D według rosnącej współrzednej x
class OrderAscX
{
public:
	bool operator()(const Point2D& pointA, const Point2D& pointB) const;
};

/// Funktor służący do sortowania punktów Point2D według malejącej współrzednej y
class OrderDescY
{
public:
	bool operator()(const Point2D& pointA, const Point2D& pointB) const;
};

/** Wypisuje współrzędną y punktu point na standardowe wyjście
* @param point
*/
void FunctionPrintX(const Point2D& point);
