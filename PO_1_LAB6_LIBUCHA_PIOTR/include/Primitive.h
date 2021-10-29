#pragma once

/// Klasa bazowa dla klas wyrażeń. Reprezentuje liczbę.
class Primitive
{
public:
	/** Konstruktor
	* @param value wartość reprezentowanej liczby
	*/
	Primitive(float value = 0);

	/** Funkcja zwracająca wartość wyrażenia
	* @return wartość reprezentowanego wyrażenia
	*/
	virtual float getValue() const;

	/// Funkcja wypisująca na ekran reprezentowane wyrażenie
	virtual void print() const;

	virtual void PrintWithValue() const;

	/** Metoda ustawiająca wartość liczby, którą reprezentuje obiekt
	* @param value
	*/
	void Set(float value);

	virtual ~Primitive();

private:
	float _value;
};