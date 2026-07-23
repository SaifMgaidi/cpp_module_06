#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


// -------------------------- free functions -------------------------------------
Base*	generate(void)
{
	int choice = rand() % 3;

	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "type: A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "type: B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "type: C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	std::cout << "warning: type not found" << std::endl;
}


// -------------------------- Destructor -------------------------------------
Base::~Base()
{
}
