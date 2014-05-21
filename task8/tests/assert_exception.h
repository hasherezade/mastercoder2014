#pragma once 
#include <sstream>

class AssertException : std::exception
{
private:

    std::string mesg;

public:

    AssertException(std::string str) throw() : mesg(str) {;}

    ~AssertException() throw() {;}

    const char* what() const throw()
    {
		return this->mesg.c_str();
    }

};
