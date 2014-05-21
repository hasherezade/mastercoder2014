/* by: hasherezade@op.pl */
#pragma once
#include <exception>
#include <stdexcept>

#include <map>
#include <string>

class Util
{
public:
	static std::string strrev(std::string &A);
};

//-----------------------------
class BaseConverter
{
public:
	BaseConverter(int maxFractionPositions = 4) 
		: maxFractPts(maxFractionPositions) { init(); }

	BaseConverter(std::string charset, int maxFractionPositions = 4) 
		: maxFractPts(maxFractionPositions) { init(charset); }

	~BaseConverter(void) {}

	/* validation */
	bool isValidBase(int base) { return (base > 1 && base <= this->valToChar.size()); }
	bool isValid(const std::string &str, int base) { return isValidBase(base) && isCharsetValid(str, base); }

	/* conversion */
	std::string Convert(int inputSystem, int outputSystem, std::string numberToConvert); //throws: invalid_argument

protected:
	/* initialization */
	void init(); //default charset
	bool init(std::string charset); //custom charset

	/* validation */
	std::string getCharsetStr(int base);
	bool isCharsetValid(const std::string &str, int base);

	/* conversion */
	int toVal(char c) { return this->charToVal[c]; }
	char toChar(int val) { return valToChar[val]; }

	std::string charToBase(char c, int base) { return valToBase(toVal(c), base); }
	std::string valToBase(int v, int base);

	/* arithmetics */
	std::string mul(const std::string &in, const int base, const int val);

	inline void adc(const int val, const int base, int &carry, std::string &out); 
	std::string add(const std::string &a1, const std::string &a2, const int base);

	/* charset conversion */
	std::map<char, int> charToVal;
	std::map<int, char> valToChar;

	/* maximal fraction length */
	int maxFractPts;
};

