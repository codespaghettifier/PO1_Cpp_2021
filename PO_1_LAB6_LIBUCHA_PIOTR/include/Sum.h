#pragma once

#include "Primitive.h"

/// Klasa reprezenutjąca wyrażenie dodawania
class Sum : public Primitive
{
public:
	/** Konstruktor
	* @param primA wyrażenie użyte w dodawaniu
	* @param primB wyrażenie użyte w dodawaniu
	*/
	Sum(Primitive& primA, Primitive& primB);

	float getValue() const override;
	void print() const override;

private:
	/// Wyrażenie użyte w dodawaniu
	Primitive& _primA;
	/// Wyrażenie użyte w dodawaniu
	Primitive& _primB;
};