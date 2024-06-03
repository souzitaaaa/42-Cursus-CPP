#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>

# include "Exception.hpp"
# include "Defines.hpp"
# include "Libft.hpp"

class Libft;

class Base
{

private:

public:
	virtual ~Base();

};

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
std::ostream &operator<<(std::ostream &out, const Base &cpy);

#endif