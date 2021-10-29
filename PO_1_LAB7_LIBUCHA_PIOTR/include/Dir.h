#pragma once

#include "FileSystemObject.hpp"

#include <vector>

/// Klasa reprezentująca katalog. Nie będzie po niej można dziedziczyć ze względu na słowo kluczowe final
class Dir final : public FileSystemObject 
{
public:
	Dir(std::string name);

	/// Wypisuje na strumień stream nazwę i tekst " (DIR)"" poprzedzoną odpowiednim wcięciem
	void print(std::ostream& stream, unsigned indent = 0) const override;
	Dir* findDir(std::string name);
	void add(FileSystemObject* object);
	FileSystemObject* get(std::string name);

	void operator+=(FileSystemObject* object);

	~Dir();
private:
	std::vector<FileSystemObject*> _objectsInDirectory;
};

