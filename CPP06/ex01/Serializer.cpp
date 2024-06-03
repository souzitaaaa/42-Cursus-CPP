#include "Serializer.hpp"
#include "Libft.hpp"

Serializer::Serializer()
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
	(void)cpy;
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &cpy)
{
	std::cout << "Copy operator called" << std::endl;
	if (this == &cpy)
		return *this;
	return *this;
}

//reinterpret_cast can directly convert a pointer (Data*)
//	to an integer type (uintptr_t) without any intermediate steps or loss of information.
uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

//reinterpret_cast can directly convert an integer (uintptr_t) back to a pointer (Data*)
//	restoring the original pointer value accurately
Data * Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

Serializer::~Serializer()
{
	std::cout << BLACK << "Destructor called" << RESET << std::endl;
}