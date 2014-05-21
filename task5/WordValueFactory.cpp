#include "WordValueFactory.h"

WordValue* WordValueFactory::createWord(const char* str)
{
    return new WordValue(str);
}
