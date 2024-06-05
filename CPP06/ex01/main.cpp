#include "Serializer.hpp"

std::ostream &operator<<(std::ostream &out, const Data &cpy)
{
    out << "Name: " << cpy.name << "\nAge: " << cpy.age << "\nPtr: " << &cpy;
    return out;
}

int main()
{
    Data a;
    Data  *b;
    a.name = "Diogo";
    a.age = 19;

    std::cout << a << std::endl;
    try {
        uintptr_t  a_ptr = Serializer::serialize(&a);
        std::cout << YELLOW << "Serializer return: \n" << RESET << a_ptr << std::endl;
        b = Serializer::deserialize(a_ptr);
        std::cout << YELLOW << "Deserializer return: \n" << RESET;
        std::cout << *b << std::endl;
        //b = new Data();
        &a == b
            ? std::cout << GREEN <<  "Serialization and deserialization succeeded!" << RESET << std::endl
            : throw Exception(BAD_SERIALIZATION);
    } catch(std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "Changing a value on A: \n" << RESET;
    a.name = "Ogoid";
    std::cout << a << std::endl;
    std::cout << *b << std::endl;
    std::cout << YELLOW << "Changing a value on B: \n" << RESET;
    b->name = "Diogo";
    std::cout << a << std::endl;
    std::cout << *b << std::endl;
}