#include "Base.hpp"


std::ostream &operator<<(std::ostream &out, const Base &cpy)
{
    out << "Ptr: " << &cpy;
    return out;
}


int main()
{
    srand(time(NULL));
    Base *a;
    for (int i = 0; i < 5; i++) {
        a = generate();
        std::cout << a << std::endl;
        identify(a);
        identify(*a);
        delete a;
    }
}