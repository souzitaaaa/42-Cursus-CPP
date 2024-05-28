#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

# include <stdexcept>

class Execption: public std::exception {
    private:
        std::string _msg;

    public:
        explicit Execption(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~Execption() throw();
};

#endif