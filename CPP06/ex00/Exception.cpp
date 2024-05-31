#include "Exception.hpp"

Exception::Exception(const std::string& msg): _msg(msg) {}

const char* Exception::what() const throw(){
    return _msg.c_str();
}

Exception::~Exception() throw() {}