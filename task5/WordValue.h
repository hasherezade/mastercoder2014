#ifndef INCLUDED_WORDVALUE_H_
#define INCLUDED_WORDVALUE_H_

#include <string>

class WordValue
{

public:

    WordValue(const char* str);

    virtual ~WordValue(){;}

    operator const char*()
    {
		return m_word.c_str();
    }

    std::string toString()
    {
		return m_word;
    }

private:

    std::string m_word;

};

#endif // INCLUDE_WORDVALUE_H_
