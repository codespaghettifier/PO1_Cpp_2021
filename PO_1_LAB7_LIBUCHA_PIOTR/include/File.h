#pragma once

#include "FileSystemObject.hpp"

/// Klasa reprezentująca plik
class File : public FileSystemObject
{
public:
	File(std::string name);

	/// Wypisuje na strumień stream nazwę i tekst " (FIlE)"" poprzedzoną odpowiednim wcięciem
	void print(std::ostream& stream, unsigned indent = 0) const override;
};