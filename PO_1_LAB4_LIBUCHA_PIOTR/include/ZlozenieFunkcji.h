#pragma once

#include "Funkcje.h"

#include <functional>
#include <vector>

///Klasa przechowująca obiekty typu std::function<double(double)> i pozwalająca wyliczyć wartość wyrażenia, będącego złożeniem przechowywanych funkcji takiego, że funkcja dodana wcześniej jest głębiej w złożeniu.
class ZlozenieFunkcji
{
public:
	/** Funkcja dodająca obiekty std::function<double(double)> do listy funkcji
	* @param function obiekt, który ma zosta dodany do listy funkcji
	*/
	void insert(std::function<double(double)> function);

	/** Funkcja obliczająca wartość wyrażenia fn(...f3(f2(f1(x)))...), gdzie f1, f2, f3, ... fn to funkcje dodane do listy w tej kolejności.
	* @param x wartość x w wyrażeniu
	* @return fn(...f3(f2(f1(x)))...), gdzie f1, f2, f3, ... fn to funkcje dodane do listy w tej kolejności.
	*/
	double wynik(double x);

	/** Operator zwracający wynik wyrażenia findex(...f3(f2(f1(x)))...), uzyskany przy ostatnim wywołaniu metody wynik(double x), gdzie f1, f2, f3, ... findex to funkcje dodane do listy w tej kolejności.
	* @param index 
	* @return wartość wyrażenia opisanego powyzej
	*/
	double operator[](unsigned index);

private:
	///Lista dodanych do złożenia funkcji
	std::vector<std::function<double(double)>> _functions = std::vector<std::function<double(double)>>();
	///Wyniki na poszczególnych etapach złożenia, uzyskane przy ostatnim wywołaniu metody wynik(double x)
	std::vector<double> _results = std::vector<double>();
};