#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* atof */
#include <math.h>       /* pow */

#include <exception>
#include <stdexcept>

#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

vector<char> ops;
vector<float> nums;

float applyOp(float num1, float num2, char op)
{
	switch (op) {
		case '+' : return num1+num2;
		case '-' : return num1-num2;
		case '*' : return num1*num2;
		case '/' : return num1/num2;
		case '^' : {
			float minus = num1 < 0 ? -1 : 1;
			num1 *= minus;
			return pow(static_cast<double>(num1), static_cast<double>(num2)) * minus;
		}
	}
	return 0;
}

bool isOperator(const char c, const char* opList = "+-*/^" )
{
	size_t opNum = strlen(opList);

	for ( int i = 0 ; i < opNum ; i++) {
		char op = opList[i];
		if (c == op) return true;
	}
	return false;
}

std::string prepare(std::string str)
{
	string outStr;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (isdigit(c) || isOperator(c)) {
			outStr.push_back(c);
			continue;
		}
		if (c == ',' || c == '.') {
			outStr.push_back('.');
			continue;
		}
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r') continue;
		throw std::invalid_argument("Invalid character supplied!");
	}
	return outStr;
}

void parse(std::string str)
{
	const char DELIMITER = ';';

	ops.clear();
	nums.clear();

	char *line = const_cast<char*> (str.c_str());
	size_t lineLen = str.length();
	int lastOp = -1;

	for (int i = 0; i < lineLen; i++ ) {
		char c = line[i];
		if ( isOperator(c) ) {
			if (c == '-' && i == lastOp + 1) continue; // negative number
			ops.push_back(c);
			lastOp = i;
			line[lastOp] = DELIMITER;
			continue;
		}
	}

	float num = 0;
	std::istringstream vStream(line);

	std::string s;
	while (std::getline(vStream, s, DELIMITER)) {
		num = atof(s.c_str());
		nums.push_back(num);
	}
}

void calcLayer(const char *opList)
{
	if (ops.size() + 1 != nums.size()) {
		cout << "Invalid content: " << (ops.size() + 1) << " != " << nums.size()  << endl;
		return;
	}

	for (int i = 0; i < ops.size(); ) {
		char op = ops[i];
		float num1 = nums[i];
		float num2 = nums[i + 1];

		if (isOperator(op, opList) ) {
			float num = applyOp(num1, num2, op);
			
			nums[i + 1] = num;

			/* remove prev num */
			vector<float>::iterator nIt = nums.begin();
			advance (nIt, i);
			if (nIt == nums.end()) break;
			nums.erase(nIt);

			/* remove op */
			vector<char>::iterator oIt = ops.begin();
			advance (oIt, i);
			if (oIt == ops.end()) break;
			ops.erase(oIt);
			continue;
		}
		i++;
	}
}

float calc(string inStr)
{
	std::string str =  prepare(inStr);
	parse(str);
	
	calcLayer("^");
	calcLayer("*/");
	calcLayer("+-");
	if (nums.size() != 1) {
		throw std::invalid_argument("ERROR: Didn't go result!");
	}
	return nums[0];
}

int main(int argc, char *argv[])
{
	std::string str = "2+3*4-6.5+-12^-1.5";
	cout <<"Calculator, version wihout brackets" <<endl;
	cout << "Input string to calculate, i.e. :\n" << str << endl;
	cout << "-----------------------------" << endl;
	getline(cin, str);
	try {
		float result = calc(str);
		cout << result << endl;

	} catch(exception e) {
		cerr << e.what() << endl;
	}
	return 0;
}

