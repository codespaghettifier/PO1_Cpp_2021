#pragma once

#include "Primitive.h"

/// Klasa reprezenutjąca wyrażenie mnożenia
class Product : public Primitive
{
public:
	/** Konstruktor
	* @param primA wyrażenie użyte w mnożeniu
	* @param primB wyrażenie użyte w mnożeniu
	*/
	Product(Primitive& primA, Primitive& primB);

	float getValue() const override;
	void print() const override;

private:
	/// Wyrażenie użyte w mnożeniu
	Primitive& _primA;
	/// Wyrażenie użyte w mnożeniu
	Primitive& _primB;
};