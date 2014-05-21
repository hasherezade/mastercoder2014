/* by: hasherezade@op.pl */
#include "BaseConverter.h"

std::string Util::strrev(std::string &A)
{
	int N = A.length();
	int last = N - 1;
	int h = N / 2;

	for (int i = 0; i < h; i++) {
		char temp = A[i];
		A[i] = A[last - i];
		A[last - i] = temp;
	}
	return A;
}

//-----------------------------

void BaseConverter::init()
{
	this->valToChar.clear();
	this->charToVal.clear();

	//init 0-9
	int i;
	char c;
	for (i = 0, c = '0'; c <= '9' ; i++, c++) {
		this->charToVal[c] = i;
		this->valToChar[i] = c;
	}
	//init A - Z
	for (c = 'A'; c <= 'Z'; c++, i++) {
		this->charToVal[c] = i;
		this->valToChar[i] = c;
	}
	//init a - z
	for (c = 'a'; c <= 'z'; c++, i++) {
		this->charToVal[c] = i;
		this->valToChar[i] = c;
	}
}

bool BaseConverter::init(std::string charset)
{
	this->valToChar.clear();
	this->charToVal.clear();

	size_t len = charset.length();
	
	for (int i = 0; i < len; i++) {
		char c = charset[i];
		this->charToVal[c] = i;
		this->valToChar[i] = c;
	}
	return (valToChar.size() == charToVal.size());
}

bool BaseConverter::isCharsetValid(const std::string &str, int base)
{
	const size_t len = str.length();
	int i = 0;
	int val;
	while (i < len && (val = toVal(str[i])) < base && str[i] == toChar(val) ) {
		i++;
	}
	if (str[i] == '.') i++;
	
	while (i < len && (val = toVal(str[i])) < base && str[i] == toChar(val) ) {
		i++;
	}
	return i == len;
}

std::string BaseConverter::valToBase(int val, int base)
{
	std::string out;
	do {
		int res = val % base;
		char c = toChar(res);
		out.push_back(c);
		val /= base;
	} while (val);

	return out;
}

std::string BaseConverter::mul(const std::string &in, const int base, const int m)
{
	std::string out;
	const int len = in.length();
	int carry = 0;
	
	for (int i = 0; i < len; i++) {
		int val = toVal(in[i]);

		val = (val * m) + carry;
		carry = val / base;

		int rem = val % base;
		char c = toChar(rem);
		out.push_back(c);
	}
	while (carry) {
		int rem = carry % base;
		carry /= base;
		char c = toChar(rem);
		out.push_back(c);
	}
	return out;
}

void BaseConverter::adc(const int val, const int base, int &carry, std::string &out)
{
	int sum = val + carry;
	int rem = sum % base;
	carry  = sum / base;
	char c = toChar(rem);
	out.push_back(c);
}

std::string BaseConverter::add(const std::string &a1, const std::string &a2, const int base)
{
	std::string out;

	const int lenA1 = a1.length();
	const int lenA2 = a2.length();

	int carry = 0;
	int i = 0;
	for (i = 0; i < lenA1 && i < lenA2; i++) {
		int val1 = toVal(a1[i]);
		int val2 = toVal(a2[i]);
		adc(val1 + val2, base, carry, out);
	}

	/* add the longer */
	for (int j = i; j < lenA1; j++) {
		int val = toVal(a1[j]);
		adc(val, base, carry, out);
	}

	for (int j = i; j < lenA2; j++) {
		int val = toVal(a2[j]);
		adc(val, base, carry, out);
	}

	while (carry) {
		adc(0, base, carry, out);
	}
	return out;
}

std::string BaseConverter::Convert(int baseIn, int baseOut, std::string str)
{
	if (!isValidBase(baseOut)|| !isValidBase(baseIn) || !isValid(str, baseIn)) {
		throw std::invalid_argument("Cannot convert: Invalid input!");
	}

	const size_t len = str.length();
	std::string out;
	int i = 0;

	do {
		int multiplier = baseIn;
		out = this->mul(out, baseOut, multiplier);

		char c = str[i];
		std::string val = this->charToBase(c, baseOut);
		out = this->add(out, val, baseOut);
		i++;

	} while(i < len && str[i] != '.');
	out = Util::strrev(out);

	if (str[i] != '.') return out;

	out.push_back('.');
	i++;

	/* calculate fraction */
	double fract = 0;
	
	for (int j = len - 1; j >= i; j--) {
		int val = this->toVal(str[j]);
		fract += val;
		fract /= baseIn;
	}

	/* convert fraction to baseOut */
	int pts = 0;
	do {
		fract *= baseOut;
		int rnd = static_cast<int>(fract);
		char c = this->toChar(rnd);
		fract -= static_cast<double>(rnd);
		out.push_back(c);
		pts++;
	} while (pts < this->maxFractPts && fract != 0);
		
	return out;
}
