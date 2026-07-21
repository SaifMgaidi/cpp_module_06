#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}


ScalarConverter::~ScalarConverter()
{
}



bool	isChar(const std::string& litteral, size_t size)
{
	if (size != 1)
		return (false);
	for (size_t i = 0; i < size; i++)
	{
		if (litteral[i] >= '0' && litteral[i] <= '9')
			return (false);
	}
	return (true);
}

bool	isInt(const std::string& litteral, size_t size)
{
	size_t	i = 0;

	if (!size)
		return (false);
	if (litteral[i] == '+' || litteral[i] == '-')
		i++;
	for (;i < size; i++)
	{
		if (litteral[i] < '0' || litteral[i] > '9')
			return (false);
	}
	if (i == 1 && (litteral[i] == '+' || litteral[i] == '-'))
		return (false);
	return (true);
}

bool	isFloat(const std::string& litteral, size_t size)
{
	int	n_digit	= 0;
	int	n_dot	= 0;
	int	n_f		= 0;

	if (size < 3)
		return (false);

	for (size_t i = 0; i < size; i++)
	{
		if (n_dot && n_f)
			return (false);
		if (litteral[i] >= '0' && litteral[i] <= '9')
			n_digit++;
		else if (litteral[i] == '.')
			n_dot++;
		else if (litteral[i] == 'f')
		{
			n_f++;
			if (!n_digit || !n_dot)
				return (false);
		}
	}

	if (!n_digit || n_dot != 1 || n_f != 1)
		return (false);
	return (true);
}

bool	isDouble(const std::string& litteral, size_t size)
{
	int	n_digit	= 0;
	int	n_dot	= 0;

	if (size < 2)
		return (false);

	for (size_t i = 0; i < size; i++)
	{
		if (litteral[i] >= '0' && litteral[i] <= '9')
			n_digit++;
		else if (litteral[i] == '.')
			n_dot++;
	}

	if (!n_digit || n_dot != 1)
		return (false);
	return (true);
}

bool	isSpecial(const std::string& litteral)
{
	if (litteral == "+inff" || litteral == "inff" || litteral == "-inff" || litteral == "nanf")
		return (true);
	else if (litteral == "+inf" || litteral == "inf" || litteral == "-inf" || litteral == "nan")
		return (true);
	return (false);
}

void	printChar(int c)
{
	if (c >= 32 && c <= 126)
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else if (c >= 0 && c <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	printInt(long l)
{
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(l) << std::endl;
}

void	printFloat(double d, bool showPosSign)
{
	bool	is_valid =	(d >= -std::numeric_limits<float>::max() &&
						d <= std::numeric_limits<float>::max()) ||
						d == std::numeric_limits<double>::infinity() ||
						d == -std::numeric_limits<double>::infinity() ||
						d != d;

	if (is_valid)
	{
		std::cout << "float: ";
		if (d == std::numeric_limits<double>::infinity() && showPosSign)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	
	}
	else
		std::cout << "float: impossible" << std::endl;
}

void	printDouble(double d, bool showPosSign)
{
	if (errno == ERANGE && d == d)
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << "double: ";
		if (d == std::numeric_limits<double>::infinity() && showPosSign)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
	}
}

void	printFromChar(int c)
{
	printChar(c);
	printInt(static_cast<long>(c));
	printFloat(static_cast<double>(c), 0);
	printDouble(static_cast<double>(c), 0);
}

void	printFromInt(long n)
{
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<int>(n));
	
	printInt(n);

	printFloat(static_cast<double>(n), 0);
	printDouble(static_cast<double>(n), 0);
}

void	printFromFloatDouble(double n, bool showPosSign)
{
	if (n < std::numeric_limits<long>::min() || n > std::numeric_limits<long>::max() || n != n)
	{	
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		printChar(static_cast<int>(n));
		printInt(static_cast<long>(n));
	}
	
	printFloat(n, showPosSign);
	printDouble(n, showPosSign);
}


void	ScalarConverter::convert(std::string litteral)
{
	size_t	size	= litteral.size();
	bool	posSign = 0;

	if (litteral[0] == '+')
		posSign = 1;

	if (isChar(litteral, size))
		printFromChar(static_cast<int>(litteral[0]));
	else if (isInt(litteral, size))
		printFromInt(std::strtol(litteral.c_str(), NULL, 10));
	else if (isFloat(litteral, size) || isDouble(litteral, size) || isSpecial(litteral))
		printFromFloatDouble(std::strtod(litteral.c_str(), NULL), posSign);
	else
		std::cout << "error: syntax" << std::endl;
}
