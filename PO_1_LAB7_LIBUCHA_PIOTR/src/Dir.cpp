#include "../include/Dir.h"

Dir::Dir(std::string name)
: FileSystemObject(name) {}

void Dir::print(std::ostream& stream, unsigned indent) const
{
	FileSystemObject::print(stream, indent);
	stream<<" (DIR)\n";
	for(FileSystemObject* object : _objectsInDirectory)
	{
		object->print(stream, indent + 1);
	}
}

void Dir::operator+=(FileSystemObject* object)
{
	_objectsInDirectory.push_back(object);
}

Dir::~Dir()
{
	std::cout<<"Deleting Dir: "<<getName()<<std::endl;

	for(FileSystemObject* object : _objectsInDirectory)
	{
		std::cout<<"About to delete "<<object->getName()<<std::endl;
		delete object;
	}

	_objectsInDirectory.clear();
}

Dir* Dir::findDir(std::string name)
{
	for(FileSystemObject* object : _objectsInDirectory)
	{
		Dir* subdirectory;
		if((subdirectory = dynamic_cast<Dir*>(object)))
		{
			if(subdirectory->getName() == name) return subdirectory;

			Dir* result = subdirectory->findDir(name);
			if(result != nullptr) return result;
		}
	}
	return nullptr;
}

void Dir::add(FileSystemObject* object)
{
	*this += object;
}

FileSystemObject* Dir::get(std::string name)
{
	for(FileSystemObject* object : _objectsInDirectory)
	{
		if(object->getName() == name) return object;

		Dir* subdirectory;
		if((subdirectory = dynamic_cast<Dir*>(object)))
		{
			FileSystemObject* result = subdirectory->get(name);
			if(result != nullptr) return result;
		}
	}
	return nullptr;
}