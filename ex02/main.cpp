#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	A		a;
	B		b;
	C		c;
	Base*	p = NULL;

	std::cout << "========== case with child object ========" << std::endl;
	std::cout << "with A:\n";
	identify(&a);
	identify(a);
	std::cout << std::endl;

	std::cout << "with B:\n";
	identify(&b);
	identify(b);
	std::cout << std::endl;

	std::cout << "with C:\n";
	identify(&c);
	identify(c);
	std::cout << std::endl;

	std::cout << "\n========== case with random object ========" << std::endl;
	p = generate();
	if (!p)
	{
		std::cout << "error: new failed" << std::endl;
		return (1);
	}
	identify(p);
	identify(*p);

	delete p;

	return (0);
}