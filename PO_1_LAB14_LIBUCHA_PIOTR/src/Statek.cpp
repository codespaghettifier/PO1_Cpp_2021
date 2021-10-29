#include "../include/Statek.hpp"

namespace Statki
{

Statek::Statek(TypStatku typ, Pozycja pozycja)
: typ(typ)
{
	pozycje.push_back(pozycja);

	switch(typ)
	{
	case CZTEROMASZTOWIEC:
		pozycje.push_back(Pozycja(pozycje[0].x + 1, pozycje[0].y));
		pozycje.push_back(Pozycja(pozycje[0].x + 2, pozycje[0].y));
		pozycje.push_back(Pozycja(pozycje[0].x + 3, pozycje[0].y));
		break;

	case TROJMASZTOWIEC:
		pozycje.push_back(Pozycja(pozycje[0].x + 1, pozycje[0].y));
		pozycje.push_back(Pozycja(pozycje[0].x + 2, pozycje[0].y));
		break;

	case DWUMASZTOWIEC:
		pozycje.push_back(Pozycja(pozycje[0].x + 1, pozycje[0].y));
		break;

	default:
		break;		
	}
}

}