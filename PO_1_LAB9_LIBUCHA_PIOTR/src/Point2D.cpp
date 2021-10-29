#include "../include/Point2D.h"

#include <cmath>
#include <iostream>

Point2D::Point2D(int x, int y)
: _x(x)
, _y(y)
, _distanceToOrigin(sqrt(x * x + y * y)) {}

bool Point2D::operator<(const Point2D& other) const
{
	return _distanceToOrigin < other._distanceToOrigin;
}

void Point2D::Print() const
{
	//Point coordinates (0, 0) distance from origin: 0
	std::cout<<"Point coordinates ("<<_x<<", "<<_y<<") distance from origin: "<<_distanceToOrigin<<std::endl;
}

void Point2D::PrintPoint(const Point2D point)
{
	point.Print();
}

void Point2D::FunctionPrintY(const Point2D& point)
{
	std::cout<<"Function print y="<<point.getY()<<std::endl;
}

bool MaxDistanceAsc(const Point2D& pointA, const Point2D& pointB)
{
	return (pointA.getX() > pointA.getY() ? pointA.getX() : pointA.getY()) < (pointB.getX() > pointB.getY() ? pointB.getX() : pointB.getY());
}

bool OrderAscX::operator()(const Point2D& pointA, const Point2D& pointB) const
{
	return pointA.getX() < pointB.getX();
}

bool OrderDescY::operator()(const Point2D& pointA, const Point2D& pointB) const
{
	return pointA.getY() > pointB.getY();
}

void FunctionPrintX(const Point2D& point)
{
	std::cout<<"Function print x="<<point.getX()<<std::endl;
}