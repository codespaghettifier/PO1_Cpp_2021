#include "include/Plansza.hpp"

using namespace Statki;
using namespace Grafika;

int main()
{
	Plansza mojaGra;

	Pozycja pozycja;

	pozycja.x = 0; pozycja.y = 0;
	dodajStatek(mojaGra, pozycja, JEDNOMASZTOWIEC);
	pozycja.x = 4; pozycja.y = 4;
	dodajStatek(mojaGra, pozycja, JEDNOMASZTOWIEC);
	pozycja.x = 6; pozycja.y = 6;
	dodajStatek(mojaGra, pozycja, JEDNOMASZTOWIEC);
	pozycja.x = 8; pozycja.y = 8;
	dodajStatek(mojaGra, pozycja, JEDNOMASZTOWIEC);

	pozycja.x = 8; pozycja.y = 0;
	dodajStatek(mojaGra, pozycja, DWUMASZTOWIEC);
	pozycja.x = 5; pozycja.y = 0;
	dodajStatek(mojaGra, pozycja, DWUMASZTOWIEC);
	pozycja.x = 0; pozycja.y = 8;
	dodajStatek(mojaGra, pozycja, DWUMASZTOWIEC);

	pozycja.x = 2; pozycja.y = 2;
	dodajStatek(mojaGra, pozycja, TROJMASZTOWIEC);
	pozycja.x = 7; pozycja.y = 2;
	dodajStatek(mojaGra, pozycja, TROJMASZTOWIEC);

	pozycja.x = 0; pozycja.y = 6;
	dodajStatek(mojaGra, pozycja, CZTEROMASZTOWIEC);

	rysujPlansze(mojaGra);

	wyczyscPlansze(mojaGra);
}