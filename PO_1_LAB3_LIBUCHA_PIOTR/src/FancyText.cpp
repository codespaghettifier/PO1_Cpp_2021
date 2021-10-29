#include "../include/FancyText.h"

#include <cstring>
#include <utility>

FancyText::FancyText(const char* string)
{
	_size = strlen(string);
	_string = new char[_size + 1];
	strcpy(_string, string);
}

FancyText::FancyText(const FancyText& other)
{
	if(this == &other) return;

	_size = other._size;
	_string = new char[_size + 1];
	strcpy(_string, other._string);
}

FancyText::FancyText(FancyText&& other)
: _string(std::exchange(other._string, nullptr))
, _size(std::exchange(other._size, 0))
, _next(std::exchange(other._next, nullptr)) {}

void FancyText::operator+=(FancyText* next)
{
	if(_next == nullptr) _next = next;
	else *_next += next;
}

void FancyText::operator+=(const char* string)
{
	*this += FancyText(string);
}

void FancyText::operator+=(FancyText&& next)
{
	FancyText* text = new FancyText(std::move(next));
	*this += text;
}

void FancyText::operator=(FancyText&& other)
{
	del();

	_string = std::exchange(other._string, nullptr);
	_size = std::exchange(other._size, 0);
	_next = std::exchange(other._next, nullptr);
}

unsigned FancyText::size() const
{
	if(_next == nullptr) return _size;
	else return _size + _next->size();
}

unsigned FancyText::fragments() const
{
	if(_next == nullptr) return 1;
	else return 1 + _next->fragments();
}

const FancyText& FancyText::fragment(unsigned index) const
{
	if(index == 0) return *this;
	else return _next->fragment(index - 1);
}

const char* FancyText::str() const
{
	return _string;
}

void FancyText::del()
{
	if(_string == nullptr) return;

	delete[] _string;
	_size = 0;
	delete _next;
}

FancyText::~FancyText()
{
	del();
}

std::ostream& operator<<(std::ostream& stream, const FancyText& text)
{
	if(text._string == nullptr) return stream;
	else if(text._next == nullptr) return stream<<text._string;
	else return stream<<text._string<<*text._next;
}