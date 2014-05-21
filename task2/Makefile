.POSIX:

CXX = g++
RM = rm -f
CFLAGS = -Wall
BIN = patterns
BIN_REQ = CLI.o ComponentInstaller.o CliInstaller.o DaemonInstaller.o MacOsDaemonInstaller.o UserPreferences.o Win7CliInstaller.o Win7DaemonInstaller.o LinuxCliInstaller.o Service.o WinXpCliInstaller.o LinuxDaemonInstaller.o ServiceInstaller.o WinXpDaemonInstaller.o MacOsCliInstaller.o DaemonInstallersFactory.o CliInstallersFactory.o test.o
BINARIES = $(BIN)
SOURCE = CLI.o ComponentInstaller.cpp CliInstaller.cpp DaemonInstaller.cpp MacOsDaemonInstaller.cpp UserPreferences.cpp Win7CliInstaller.cpp Win7DaemonInstaller.cpp LinuxCliInstaller.cpp Service.cpp WinXpCliInstaller.cpp LinuxDaemonInstaller.cpp ServiceInstaller.cpp WinXpDaemonInstaller.cpp MacOsCliInstaller.cpp DaemonInstallersFactory.cpp CliInstallersFactory.cpp test.cpp
OBJ = $(SOURCE:.cpp=.o)

.PHONY: all clean

all: $(BIN)

clean:
	$(RM) $(BINARIES) $(OBJ)

$(BIN): $(BIN_REQ)
	$(CXX) $(CFLAGS) -o $@ $(BIN_REQ)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< 
