.POSIX:

CXX = g++
RM = rm -f
CFLAGS = -Wall
BIN = wyznacz_droge
BIN_REQ = Node.o Grid.o main.o
BINARIES = $(BIN)
SOURCE = Node.cpp Grid.cpp main.cpp
OBJ = $(SOURCE:.cpp=.o)

.PHONY: all clean

all: $(BIN)

clean:
	$(RM) $(BINARIES) $(OBJ)

$(BIN): $(BIN_REQ)
	$(CXX) $(CFLAGS) -o $@ $(BIN_REQ)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< 
