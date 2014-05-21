#include "TextDistanceServiceTest.h"

#include "JaroWinkerTextDistance.h"
#include "LevensteinTextDistance.h"
#include "TextSimilarityServiceImpl.h"

#include <cstdio>

TextDistanceServiceTest::TextDistanceServiceTest()
{
	service = NULL;
	wordFactory = NULL;
	configurationService = NULL;
}

TextDistanceServiceTest::~TextDistanceServiceTest()
{
	delete(service);
	delete(wordFactory);
	delete(configurationService);
}

void TextDistanceServiceTest::setUp()
{
	this->configurationService = new MockConfiguration();
	this->wordFactory = new WordValueFactory();

	TextSimilarityServiceImpl *tService = new TextSimilarityServiceImpl(configurationService);
	tService->registerStrategy(DistanceType::JARO_WINKLER, new JaroWinkerTextDistance());
	tService->registerStrategy(DistanceType::LEVENSHTEIN, new LevensteinTextDistance());

	this->service = tService;

	this->registerTester(DistanceType::JARO_WINKLER, new Tester());
	this->registerTester(DistanceType::LEVENSHTEIN, new Tester());

	ASSERT_NOTNULL(configurationService);
	ASSERT_NOTNULL(service);
	ASSERT_NOTNULL(wordFactory);

	initJaroTester();
	initLevTester();
}

void TextDistanceServiceTest::registerTester(DistanceType type, Tester* tester)
{
	this->testers[type] = tester;
}

TestCase* TextDistanceServiceTest::initTestCase(const char* s1, const char* s2, double out)
{
	WordValue *word1 = wordFactory->createWord(s1);
	WordValue *word2 = wordFactory->createWord(s2);
	
	return (new TestCase(word1, word2, out));
}

void TextDistanceServiceTest::initJaroTester()
{
	Tester* t = testers[DistanceType::JARO_WINKLER];
	ASSERT_NOTNULL(t);
	t->addCase( initTestCase("kitten", "sitten", 0.88) );
	t->addCase( initTestCase("dwayne", "duane", 0.84) );
	t->addCase( initTestCase("yvette", "yevett", 0.9) );
	t->addCase( initTestCase("tanya", "tonya", 0.88) );
	t->addCase( initTestCase("shackleford", "shackelford", 0.983471) );
	t->addCase( initTestCase(
"Adobe Reader X is a powerful software solution developed by Adobe Systems to view, create, manipulate, print and manage files in Portable Document Format (PDF). Since version 10 it includes the Protected Mode, a sandbox technology similar to the one in Google Chrome which improves the overall security of the product.", 
"Adobe Reader X fails to validate the input when parsing an embedded BMP RLE encoded image. Arbitrary code execution in the context of the sandboxed process is proved possible after a malicious bmp image triggers a heap overflow. Quick links: White paper, Exploit generator in python and PoC.pdf for Reader 10.1.4. ", 
		0.765039) 
		);
}

void TextDistanceServiceTest::initLevTester()
{
	Tester* t = testers[DistanceType::LEVENSHTEIN];
	ASSERT_NOTNULL(t);
	t->addCase( initTestCase("kitten", "sitten", 0.83) );
	t->addCase( initTestCase("dwayne", "duane", 0.666667) );
	t->addCase( initTestCase("yvette", "yevett", 0.666667) );
	t->addCase( initTestCase("tanya", "tonya", 0.8) );
	t->addCase( initTestCase("shackleford", "shackelford", 0.818182) );
	t->addCase( initTestCase(
"Adobe Reader X is a powerful software solution developed by Adobe Systems to view, create, manipulate, print and manage files in Portable Document Format (PDF). Since version 10 it includes the Protected Mode, a sandbox technology similar to the one in Google Chrome which improves the overall security of the product.", 
"Adobe Reader X fails to validate the input when parsing an embedded BMP RLE encoded image. Arbitrary code execution in the context of the sandboxed process is proved possible after a malicious bmp image triggers a heap overflow. Quick links: White paper, Exploit generator in python and PoC.pdf for Reader 10.1.4. ", 
		0.216981) 
		);
}

TestCase* TextDistanceServiceTest::initTestCase(const char* s1, const char* s2)
{
	WordValue *word1 = wordFactory->createWord(s1);
	WordValue *word2 = wordFactory->createWord(s2);
	
	return (new TestCase(word1, word2));
}

void TextDistanceServiceTest::distanceIsNotNull()
{
	TestCase* t = initTestCase("kitten", "sitten");
	t->testOutNotNull(service);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::distanceIsLessOrEqualOne()
{
	TestCase* t = initTestCase("kitten", "sitten");
	t->testOutLessOrEqualMax(service, 1.0);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::distanceIsMoreOrEqualZero()
{
	TestCase* t = initTestCase("kitten", "sitten");
	t->testOutMoreOrEqualMin(service, 0.0);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::distanceIsOneForIdenticalStrings()
{
	TestCase* t = initTestCase("kitten", "kitten", 1.0);
	t->testOutEq(service);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::calculatedJaroWinklerDistanceForDifferentStrings()
{
	configurationService->useJaroWinkler();

	TestCase* t = initTestCase("kitten", "sitten", 0.88);
	t->testOutEqWithPrecision(service, 0.01);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::calculatedLevenshteinDistanceForDifferentStrings()
{
	configurationService->useLevenshtein();

	TestCase* t = initTestCase("kitten", "sitten", 0.83);
	t->testOutEqWithPrecision(service, 0.01);
	delete t;
	printf("[+] %s\n", service->code());
}

void TextDistanceServiceTest::testCornerCases()
{
	distanceIsNotNull();
	distanceIsLessOrEqualOne();
	distanceIsMoreOrEqualZero();
	distanceIsOneForIdenticalStrings();
}

void TextDistanceServiceTest::testAll()
{
	this->testCornerCases();
	Tester *t = testers[configurationService->getDistnanceType()];
	t->testOutEqWithPrecision(service, 0.01);
}

void TextDistanceServiceTest::testJaroWinker()
{
	configurationService->useJaroWinkler();
	testAll();
}

void TextDistanceServiceTest::testLevenstein()
{
	configurationService->useLevenshtein();
	testAll();
}