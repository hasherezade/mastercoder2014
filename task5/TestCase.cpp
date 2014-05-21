#include "TestCase.h"

TestCase::TestCase(WordValue *word1, WordValue *word2, double expectedOut)
{
	ASSERT_NOTNULL(word1);
	ASSERT_NOTNULL(word2);

	this->word1 = word1;
	this->word2 = word2;

	this->expectedOut = expectedOut;
	isOutInit = true;
}

TestCase::TestCase(WordValue *word1, WordValue *word2)
{
	ASSERT_NOTNULL(word1);
	ASSERT_NOTNULL(word2);

	this->word1 = word1;
	this->word2 = word2;

	this->expectedOut = 0.0;
	isOutInit = false;
}

void TestCase::testOutNotNull(AbstractTextDistance *calculator) const
{
	ASSERT_NOTNULL(calculator);
	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);
	
	ASSERT_NOTNULL(distance);
	delete distance;
}

void TestCase::testOutEq(AbstractTextDistance *calculator) const
{
	ASSERT_NOTNULL(calculator);
	if (!this->isOutInit) return;

	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);
	double out = *distance;
	ASSERT_EQUAL(this->expectedOut, out);
	delete distance;
}

void TestCase::testOutEqWithPrecision(AbstractTextDistance *calculator, double precision) const
{
	ASSERT_NOTNULL(calculator);
	if (!this->isOutInit) return;
	
	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);
	double out = *distance;
	//printf("expectedOut = %f vs %f for: %s %s\n", this->expectedOut, out, str1.c_str(), str2.c_str());
	ASSERT_EQUAL3(this->expectedOut, out, precision);
	delete distance;
}

void TestCase::testOutLessOrEqualMax(AbstractTextDistance *calculator, double max) const
{
	ASSERT_NOTNULL(calculator);

	DistanceValue maxDistance = DistanceValue(max);
	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);

	ASSERT_TRUE(*distance <= maxDistance);
	delete distance;
}

void TestCase::testOutMoreOrEqualMin(AbstractTextDistance *calculator, double min) const
{
	ASSERT_NOTNULL(calculator);

	DistanceValue minDistance = DistanceValue(min);
	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);

	ASSERT_TRUE(*distance >= minDistance);
	delete distance;
}

void TestCase::printResult(AbstractTextDistance *calculator, FILE *fOut) const
{
	ASSERT_NOTNULL(calculator);
	
	DistanceValue *distance = calculator->calculateDistance(*word1, *word2);
	double out = *distance;
	fprintf(fOut, "%f\n%s\n%s\n\n", out, word1->toString().c_str(), word2->toString().c_str());

	delete distance;
}


//Tester:

Tester::~Tester()
{
	std::vector<TestCase*>::iterator itr;
	for (itr = tCases.begin(); itr != tCases.end(); itr++) {
		const TestCase* test = *itr;
		delete test;
	}
	tCases.clear();
}

void Tester::printResults(AbstractTextDistance *calculator, FILE *fOut)
{
	std::vector<TestCase*>::iterator itr;
	for (itr = tCases.begin(); itr != tCases.end(); itr++) {
		const TestCase* test = *itr;
		test->printResult(calculator, fOut);
	}
}

void Tester::testOutEq(AbstractTextDistance *calculator)
{
	std::vector<TestCase*>::iterator itr;
	for (itr = tCases.begin(); itr != tCases.end(); itr++) {
		const TestCase* test = *itr;
		test->testOutEq(calculator);
		printf("[+] EQ %s\n", calculator->code());
	}
}

void Tester::testOutEqWithPrecision(AbstractTextDistance *calculator, double precision)
{
	std::vector<TestCase*>::iterator itr;
	for (itr = tCases.begin(); itr != tCases.end(); itr++) {
		const TestCase* test = *itr;
		test->testOutEqWithPrecision(calculator, precision);
		printf("[+] EQ,prec %g %s\n", precision, calculator->code());
	}
}