#pragma once

#include <iostream>

class FancyText
{
	friend std::ostream& operator<<(std::ostream& stream, const FancyText& text);
public:
	FancyText() = default;

	///Konstruktor 
	FancyText(const char* string);

	///Konstruktor kopiujący
	FancyText(const FancyText& other);

	///Konstruktor przenoszący
	FancyText(FancyText&& other);

	/** Operator dodający obiekt klasy FancyText na koniec listy
	* @param next obiekt FancyText dodawany na koniec listy
	*/
	void operator+=(FancyText* next);

	/** Operator tworzący obiekt klasy FancyText na podstawie stringa i umiaszczający go na końcu listy
	* @param string text do umieszczenia na końcu
	*/
	void operator+=(const char* string);

	/** Operator przenoszący obiekt klasy FancyText na koniec listy
	* @param next obiekt FancyText przenoszony na koniec listy
	*/
	void operator+=(FancyText&& next);

	///Operator przypisania przenoszącego
	void operator=(FancyText&& other);

	/** Funkcja zwaracjąca długość tekstu zwartego w całej liście
	* @return długość tekstu zawartego w całej liście
	*/
	unsigned size() const;

	/** Funkcja zwaracjąca długość listy
	* @return długość listy
	*/
	unsigned fragments() const;

	/** Funkcja zwracająca element listy o indeksie index
	* @param index indeks elementu listy, który ma zostać zwrócony
	* @return element listy o indeksie index
	*/
	const FancyText& fragment(unsigned index) const;

	/** Funkcja zwracająca tekst zawarty w elemencie listy, na rzecz którego została wywołana
	* @return tekst zawarty w elemencie
	*/
	const char* str() const;

	// Funkcja zwalniająca pamięć zaalokowaną dla elementów listy 
	void del();

	~FancyText();

private:
	/// Tekst przechowywany w elemencie listy
	char* _string = nullptr;

	/// Długość przechowywanego tekstu
	unsigned _size = 0;

	///Wskaźnik na kolejny element list
	FancyText* _next = nullptr;
};

/** Operator wypisujący tekst zawarty w liście do strumienia std::ostream i zwracający ten strumień
* @param stream strumień, do którego ma zostać wypisany tekst z listy
* @param tekst lista z tekstem do wypisania
* @return strumień stream
*/
std::ostream& operator<<(std::ostream& stream, const FancyText& text);