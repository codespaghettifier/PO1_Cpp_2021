#include "../include/File.h"

File::File(std::string name)
: FileSystemObject(name) {}

void File::print(std::ostream& stream, unsigned indent) const
{
	FileSystemObject::print(stream, indent);
	stream<<" (FILE)\n";
}