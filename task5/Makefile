.POSIX:

CXX = g++
RM = rm -f
LDFLAGS=
CXXFLAGS = -Wall -std=gnu++11

EXECUTABLE = test_me

SOURCES =	DistanceValue.cpp \
		WordValue.cpp \
		WordValueFactory.cpp \
		TextSimilarityServiceImpl.cpp \
		JaroWinkerTextDistance.cpp \
		LevensteinTextDistance.cpp \
		TestAssert.cpp \
		TextDistanceServiceTest.cpp \
		TestCase.cpp \
		MockConfiguration.cpp \
		main.cpp

HEADERS =	AbstractTextDistance.h \
		ConfigurationService.h \
		DistanceType.h \
		DistanceValue.h \
		WordValue.h \
		WordValueFactory.h \
		TextSimilarityServiceImpl.h \
		JaroWinkerTextDistance.h \
		LevensteinTextDistance.h \
		TestAssert.h \
		TextDistanceServiceTest.h \
		TestCase.h \
		MockConfiguration.h

OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean test archive debug

all: $(SOURCES) $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

archive:
	zip -r word_distance.zip Makefile $(HEADERS) $(SOURCE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -g $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
