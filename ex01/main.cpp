#include "Serializer.hpp"

int	main(void)
{
	Data	d;
	uintptr_t	raw = 0;
	Data		*p = NULL;

	d.a = 42;

	raw = Serializer::serialize(&d);
	p = Serializer::deserialize(raw);

	if (p == &d)
	{
		std::cout << p << " == " << &d << std::endl;
		std::cout << "d.a ==  " << d.a << std::endl;
		std::cout << "p->a == " << p->a << std::endl;
	}
	else
		std::cout << "warnig: serialization/deserialization failed" << std::endl;
	return (0);
}