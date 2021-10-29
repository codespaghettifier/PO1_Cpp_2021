#pragma once

#include <string>
#include <sstream>
#include <iostream>

/// Klasa bazowa dla wszystkich obiektów w systemie plików.
class FileSystemObject
{
public:
	FileSystemObject(std::string name);

	/// Wypisuje na strumień stream nazwę obietku poprzedzoną wcięciem o szerokości indent
	virtual void print(std::ostream& stream, unsigned indent = 0) const;
	inline std::string getName() const;

	virtual ~FileSystemObject() {};

protected:
	std::string _name;
};

inline std::string FileSystemObject::getName() const
{
	return _name;
}

std::ostream& operator<<(std::ostream& stream, const FileSystemObject& object);