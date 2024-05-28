#include "Exception.hpp"

Execption::Execption(const std::string& msg): _msg(msg) {}

const char* Execption::what() const throw(){
    return _msg.c_str();
}

Execption::~Execption() throw() {}