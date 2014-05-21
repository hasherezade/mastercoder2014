#include <string>
#include <iostream>
#include "BaseConverter.h"

using namespace std;

int main()
{
	int fractionMaxLen = 4;
	BaseConverter conv(fractionMaxLen);

	int bIn;
	int bOut;
	std::string str;

	cout << "Input system:\t";
	cin >> bIn;
	cout << "Output system:\t";
	cin >> bOut;
	cout << "toConvert:\t";
	cin >> str;
	cout << endl;

	int ret = 0;
	try {
		std::string convOut = conv.Convert(bIn, bOut, str);
		cout << "Output: \n"<< convOut << std::endl;

	} catch(exception &e) {
		std::cerr << e.what() << std::endl;
		ret = -1;
	}
	return ret;
}