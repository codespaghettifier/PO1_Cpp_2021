#pragma once

#include "Primitive.h"

/// Klasa reprezenutjąca wyrażenie dzielenia
class Ratio : public Primitive
{
public:
	/** Konstruktor
	* @param primA wyrażenie użyte w dzieleniu jako licznik
	* @param primB wyrażenie użyte w dzieleniu jako mianownik
	*/
	Ratio(Primitive& primA, Primitive& primB);

	float getValue() const override;
	void print() const override;

private:
	/// Wyrażenie użyte w dzieleniu jako licznik
	Primitive& _primA;
	/// Wyrażenie użyte w dzieleniu jako mianownik
	Primitive& _primB;
};