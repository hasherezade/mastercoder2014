.POSIX:

CXX = g++
RM = rm -f
CFLAGS = -Wall
BIN = czarnobyl
BIN_REQ = Walls.o main.o
BINARIES = $(BIN)
SOURCE = Walls.cpp main.cpp
OBJ = $(SOURCE:.cpp=.o)

.PHONY: all clean

all: $(BIN)

clean:
	$(RM) $(BINARIES) $(OBJ)

$(BIN): $(BIN_REQ)
	$(CXX) $(CFLAGS) -o $@ $(BIN_REQ)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< 
