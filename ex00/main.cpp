#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (1);
	ScalarConverter::convert(av[1]);
	 std::cout << std::numeric_limits<float>::digits10 << '\n';
    std::cout << std::numeric_limits<float>::max_digits10 << '\n';
	return (0);
}