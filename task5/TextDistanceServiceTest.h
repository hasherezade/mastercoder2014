#include "WordValueFactory.h"
#include "AbstractTextDistance.h"
#include "MockConfiguration.h"
#include "TestCase.h"

#include <iostream>
#include <map>

class TextDistanceServiceTest
{

private:
    AbstractTextDistance *service;
    WordValueFactory *wordFactory;
    MockConfiguration *configurationService;

	std::map<DistanceType, Tester*> testers;
	void registerTester(DistanceType, Tester*);

	TestCase* initTestCase(const char* s1, const char* s2, double out);
	TestCase* initTestCase(const char* s1, const char* s2);

	void initLevTester();
	void initJaroTester();
	void testCornerCases();
	void testAll();

public:
    TextDistanceServiceTest();
    virtual ~TextDistanceServiceTest();

    void setUp();

    void distanceIsNotNull();
    void distanceIsLessOrEqualOne();
    void distanceIsMoreOrEqualZero();
    void distanceIsOneForIdenticalStrings();

    void calculatedJaroWinklerDistanceForDifferentStrings();
    void calculatedLevenshteinDistanceForDifferentStrings();

	void testJaroWinker();
	void testLevenstein();
};