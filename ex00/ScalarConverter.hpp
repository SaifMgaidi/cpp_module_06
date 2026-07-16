#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>


class ScalarConverter
{
public:
	// Member Functions
	static void	convert(std::string litteral);
private:
	// Constructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	
	// Operators
	ScalarConverter&	operator=(const ScalarConverter& other);
	
	// Destructor
	~ScalarConverter();
};


#endif