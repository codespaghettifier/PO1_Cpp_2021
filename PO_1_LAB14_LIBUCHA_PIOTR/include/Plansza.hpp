#pragma once

#include "Statek.hpp"

namespace Statki
{

class Plansza
{
public:
	Plansza(unsigned width = 10, unsigned height = 10);

	void dodajStatek(Pozycja pozycja, TypStatku typStatku);

	inline unsigned getWidth() const;
	inline unsigned getHeight() const;
	bool isOccupied(unsigned x, unsigned y) const;
	void clear();

private:
	unsigned width;
	unsigned height;
	std::vector<Statek> czteromasztowce;
	std::vector<Statek> trojmasztowce;
	std::vector<Statek> dwumasztowce;
	std::vector<Statek> jednomasztowce;			
};	

inline unsigned Plansza::getWidth() const
{
	return width;
}

inline unsigned Plansza::getHeight() const
{
	return height;
}

void dodajStatek(Plansza& plansza, Pozycja pozycja, TypStatku typStatku);

}

namespace Grafika
{

void rysujPlansze(Statki::Plansza& plansza);

void wyczyscPlansze(Statki::Plansza& plansza);

}