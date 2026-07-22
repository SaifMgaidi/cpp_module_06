#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
	// Static member functions
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	// Constructors
	Serializer();
	Serializer(const Serializer& other);
	
	// Operators
	Serializer&	operator=(const Serializer& other);
	
	// Destructor
	~Serializer();
};

#endif