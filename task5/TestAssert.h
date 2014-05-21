#ifndef INCLUDED_TESTASSERT_H_
#define INCLUDED_TESTASSERT_H_

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

template<typename T>
void assert_equal(T v1, T v2, const char* filename, int linenumber)
{
    if (v1 != v2)
    {
	std::stringstream mesg;
	mesg << "Assertion failed: ";
	mesg << v1;
	mesg << " == ";
	mesg << v2;
	mesg << " at ";
	mesg << filename;
	mesg << ":";
	mesg << linenumber;
	throw new AssertException(mesg.str());
    }
}

template<typename T>
void assert_equal3(T v1, T v2, T acc, const char* filename, int linenumber)
{
    T diff = v1 - v2;
    if ((diff > acc) || (-diff > acc))
    {
		std::stringstream mesg;
		mesg << "Assertion failed: ";
		mesg << v1;
		mesg << " == ";
		mesg << v2;
		mesg << " with accuracy ";
		mesg << acc;
		mesg << " at ";
		mesg << filename;
		mesg << ":";
		mesg << linenumber;
		throw new AssertException(mesg.str());
    }
}

template<typename T>
void assert_notnull(T *v, const char* filename, int linenumber)
{
    if (v == NULL)
    {
		std::stringstream mesg;
		mesg << "Assertion failed: ";
		mesg << v;
		mesg << " is NULL at ";
		mesg << filename;
		mesg << ":";
		mesg << linenumber;
		throw new AssertException(mesg.str());
    }
}

void assert_true(bool condition, const char* message, const char* filename, int linenumber);

#define ASSERT_EQUAL(v1, v2) assert_equal(v1, v2, __FILE__, __LINE__)
#define ASSERT_EQUAL3(v1, v2, v3) assert_equal3(v1, v2, v3, __FILE__, __LINE__)
#define ASSERT_TRUE(cond) assert_true(cond, #cond, __FILE__, __LINE__)
#define ASSERT_NOTNULL(val) assert_notnull(val, __FILE__, __LINE__)

#endif // INCLUDED_TESTASSERT_H_
