#include "Serializer.hpp"

// ---------------------- Constructors ------------------------------------
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}


// ---------------------- Operators ------------------------------------
Serializer&	Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}


// ---------------------- Destructor ------------------------------------
Serializer::~Serializer()
{
}


// ---------------------- Static member functions ------------------------------------
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}