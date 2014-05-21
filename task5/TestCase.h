#ifndef INCLUDED_TESTCASE_H_
#define INCLUDED_TESTCASE_H_

#include <string>
#include "AbstractTextDistance.h"
#include "TestAssert.h"
#include <vector>

class TestCase {

private:
	WordValue *word1;
	WordValue *word2;

	double expectedOut;
	bool isOutInit;

public:
	TestCase(WordValue *word1, WordValue *word2, double expectedOut);
	TestCase(WordValue *word1, WordValue *word2);

	virtual ~TestCase() { delete word1; delete word2; }

	void testOutNotNull(AbstractTextDistance *calculator) const;

	void testOutEq(AbstractTextDistance *calculator) const;
	void testOutEqWithPrecision(AbstractTextDistance *calculator, double precision) const;

	void testOutLessOrEqualMax(AbstractTextDistance *calculator, double max) const;
	void testOutMoreOrEqualMin(AbstractTextDistance *calculator, double min) const;

	void printResult(AbstractTextDistance *calculator, FILE *fOut) const;
};


class Tester
{
public:
	Tester() { }
	~Tester();

	void addCase(TestCase* testCase) { tCases.push_back(testCase); }

	void printResults(AbstractTextDistance *calculator, FILE *fOut);
	void testOutEq(AbstractTextDistance *calculator);
	void testOutEqWithPrecision(AbstractTextDistance *calculator, double precision);

private:
	std::vector<TestCase*> tCases;
};


#endif // INCLUDED_TESTCASE_H_
