#include "Base.hpp"
#include "Libft.hpp"

Base *generate() {
	switch (rand() % 4) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		case 3:
			return new D;
	}
	return NULL;
}

//dynamic_cast with pointers, it will return nullptr if the cast is not successful
void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "Class A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "Class B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << CYAN << "Class C" << RESET << std::endl;
	else
		std::cout << RED << "Invalid Class Type" << RESET << std::endl;
}

//dynamic_cast with references, if the cast is not successful, it will throw a
//	std::bad_cast exception. This is because references cannot be nullptr
void identify(Base &p) {
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN << "Class A" << RESET << std::endl;
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << YELLOW << "Class B" << RESET << std::endl;
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << CYAN << "Class C" << RESET << std::endl;
        return;
    } catch (const std::exception &e) {}
    std::cout << RED << "Invalid Class Type" << RESET << std::endl;
}


Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}