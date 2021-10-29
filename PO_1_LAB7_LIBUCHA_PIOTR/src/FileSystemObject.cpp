#include "../include/FileSystemObject.hpp"

FileSystemObject::FileSystemObject(std::string name)
: _name(name) {}

void FileSystemObject::print(std::ostream& stream, unsigned indent) const
{
	for(unsigned a = 0; a < indent; a++) stream<<"\t";
	stream<<_name;
}

std::ostream& operator<<(std::ostream& stream, const FileSystemObject& object)
{
	object.print(stream);
	return stream;
}
