#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

# include <stdexcept>

class Exception: public std::exception {
    private:
        std::string _msg;

    public:
        explicit Exception(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~Exception() throw();
};

#endif