#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

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

typedef struct Data {
	std::string name;
	int	age;
} Data;

class Serializer
{

private:
	Serializer();
	Serializer(const Serializer &cpy);
	Serializer &operator=(const Serializer &cpy);

public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &out, const Data &cpy);

#endif