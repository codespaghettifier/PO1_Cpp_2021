#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

/// Klasa reprezentująca rekord w danych. Zwaiera dzień tygonia i listę numerów.
class Data
{
public:
	Data(std::string day, std::vector<float> numbers);

	/// Wypisuje rekord na standardowe wyjście
	void print() const;
	inline const std::vector<float>& getNumbers() const;

private:
	std::string _day;
	std::vector<float> _numbers;
};

inline const std::vector<float>& Data::getNumbers() const
{
	return _numbers;
}
