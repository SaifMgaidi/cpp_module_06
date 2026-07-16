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
		else
			return (false);
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
		else
			return (false);
		
	}

	if (!n_digit || n_dot != 1)
		return (false);
	return (true);
}

long	convertStringToInt(std::string litteral, size_t size)
{
	long	n	= 0;
	size_t	i	= 0;
	int		f	= 1;

	if (!size)
		return (std::numeric_limits<long>::max());

	if (litteral[i] == '+' || litteral[i] == '-')
	{
		if (litteral[i] == '-')
			f = -f;
		i++;
	}
	
	while (litteral[i])
	{
		if (litteral[i] < '0' || litteral[i] > '9')
			return (std::numeric_limits<long>::max());
		n *= 10;
		n += litteral[i] - '0';
		i++;
	}
	return (n * f);
}

double	convertStringToFloat(std::string litteral, size_t size)
{
	double	n	= 0.0;
	int		f	= 1;
	size_t	i	= 0;

	if (!size - 1)
		return (std::numeric_limits<double>::max());

	if (litteral[i] == '+' || litteral[i] == '-')
	{
		if (litteral[i] == '-')
			f = -f;
		i++;
	}

	return (n * f);
}


void	printFromChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printToInt(int n)
{
	if (n >= 32 && n <= 126)
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;	
}

void	ScalarConverter::convert(std::string litteral)
{
	size_t	size	= litteral.size();
	long	i		= 0;
	float	f		= 0.0f;
	double	d		= 0.0;

	if (isChar(litteral, size))
		printFromChar(litteral[0]);
	else if (isInt(litteral, size))
	{
		i = convertStringToInt(litteral, size);
		if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
			std::cout << "error: int overflow." << std::endl;
		else
			printToInt(i);
	}
}
