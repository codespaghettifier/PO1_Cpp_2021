#include "../include/Plansza.hpp"

#include <iostream>

namespace Statki
{

Plansza::Plansza(unsigned width, unsigned height)
: width(width)
, height(height) {}

void Plansza::dodajStatek(Pozycja pozycja, TypStatku typStatku)
{
	switch(typStatku)
	{
	case CZTEROMASZTOWIEC:
		czteromasztowce.push_back(Statek(typStatku, pozycja));
		break;

	case TROJMASZTOWIEC:
		trojmasztowce.push_back(Statek(typStatku, pozycja));
		break;

	case DWUMASZTOWIEC:
		dwumasztowce.push_back(Statek(typStatku, pozycja));
		break;

	case JEDNOMASZTOWIEC:
		jednomasztowce.push_back(Statek(typStatku, pozycja));
		break;	
	}
}

bool Plansza::isOccupied(unsigned x, unsigned y) const
{
	for(unsigned a = 0; a < czteromasztowce.size(); a++)
	{
		for(unsigned b = 0; b < czteromasztowce[a].pozycje.size(); b++)
		{
			if(czteromasztowce[a].pozycje[b].x == x && czteromasztowce[a].pozycje[b].y == y) return true;
		}
	}

	for(unsigned a = 0; a < trojmasztowce.size(); a++)
	{
		for(unsigned b = 0; b < trojmasztowce[a].pozycje.size(); b++)
		{
			if(trojmasztowce[a].pozycje[b].x == x && trojmasztowce[a].pozycje[b].y == y) return true;
		}
	}

	for(unsigned a = 0; a < dwumasztowce.size(); a++)
	{
		for(unsigned b = 0; b < dwumasztowce[a].pozycje.size(); b++)
		{
			if(dwumasztowce[a].pozycje[b].x == x && dwumasztowce[a].pozycje[b].y == y) return true;
		}
	}

	for(unsigned a = 0; a < jednomasztowce.size(); a++)
	{
		for(unsigned b = 0; b < jednomasztowce[a].pozycje.size(); b++)
		{
			if(jednomasztowce[a].pozycje[b].x == x && jednomasztowce[a].pozycje[b].y == y) return true;
		}
	}

	return false;
}

void Plansza::clear()
{
	czteromasztowce.clear();
	trojmasztowce.clear();
	dwumasztowce.clear();
	jednomasztowce.clear();
}


void dodajStatek(Plansza& plansza, Pozycja pozycja, TypStatku typStatku)
{
	plansza.dodajStatek(pozycja, typStatku);
}

}

namespace Grafika
{

void rysujPlansze(Statki::Plansza& plansza)
{
	for(unsigned y = 0; y < plansza.getHeight(); y++)
	{
		for(unsigned x = 0; x < plansza.getWidth(); x++)
		{
			if(plansza.isOccupied(x, y)) std::cout<<"X ";
			else std::cout<<". ";
		}
		std::cout<<std::endl;
	}
}

void wyczyscPlansze(Statki::Plansza& plansza)
{
	plansza.clear();
}

}