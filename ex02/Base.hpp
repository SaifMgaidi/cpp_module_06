#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>


class Base
{
public:
	// destructor
	virtual ~Base();
private:
	/* data */
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif