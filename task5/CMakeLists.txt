cmake_minimum_required(VERSION 2.8)
project (text_sim_calc)

set (hdrs
	AbstractTextDistance.h
	ConfigurationService.h
	DistanceType.h
	DistanceValue.h
	WordValue.h
	WordValueFactory.h
	TextSimilarityServiceImpl.h
	JaroWinkerTextDistance.h
	LevensteinTextDistance.h
	TestAssert.h
	TextDistanceServiceTest.h
	TestCase.h
	MockConfiguration.h
)

set (srcs
	DistanceValue.cpp
	WordValue.cpp
	WordValueFactory.cpp
	TextSimilarityServiceImpl.cpp
	JaroWinkerTextDistance.cpp
	LevensteinTextDistance.cpp
	TestAssert.cpp
	TextDistanceServiceTest.cpp
	TestCase.cpp
	MockConfiguration.cpp
	main.cpp
)

add_executable (text_sim_calc ${hdrs} ${srcs})

