#pragma once

#include "Data.h"

#include <functional>

/// Klasa reprezentujaca tablicę danych typu Data, którą można sortować na różne sposoby.
class Table
{
public:
	/// Ilość liczb w rekordzie o najmniejszej ilosci liczb
	unsigned minRow = -1;

	/// Dodaje rekord do tablicy
	void operator+=(Data data);

	/// Sortuje i tablicę rekordów zgodnie z przekazaną funkcją compare. Zwraca const referencję na obiekt, na rzecz którego metoda została wywołana.
	const Table& sortBy(std::function<bool(const Data& a, const Data& b)> compare);
	
	/// Sortuje rekordy w kolejności od najmniejszego do najwięszego pod względem numeru o indeksie column w danym rekordzie. Jeżeli w co najmniej jeden rekord w tablicy zawiera mniej numerów, niż potrzeba do sortowania, na ekran wypisywany jest adekwatny komunikat. Zwraca const referencję na obiekt, na rzecz którego metoda została wywołana.
	const Table& sort(unsigned column);

	/// Wypisuje tablicę rekordów na standardowe wyjście
	void print() const;

private:
	std::vector<Data> _data;
};
