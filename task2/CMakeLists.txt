cmake_minimum_required(VERSION 2.8)
project (discover_pattern)

set (hdrs
	OperatingSystem.h
	CLI.h
	Daemon.h
	Configuration.h
	RemoteApplication.h
	RemoteDaemon.h
	ComponentInstaller.h
	CliInstaller.h
	DaemonInstaller.h
	MacOsDaemonInstaller.h
	UserPreferences.h
	Win7CliInstaller.h
	Win7DaemonInstaller.h
	LinuxCliInstaller.h
	Service.h
	WinXpCliInstaller.h
	LinuxDaemonInstaller.h
	ServiceInstaller.h
	WinXpDaemonInstaller.h
	MacOsCliInstaller.h
	DaemonInstallersFactory.h
	CliInstallersFactory.h
)

set (srcs
	CLI.cpp
	ComponentInstaller.cpp
	CliInstaller.cpp
	DaemonInstaller.cpp
	MacOsDaemonInstaller.cpp
	UserPreferences.cpp
	Win7CliInstaller.cpp
	Win7DaemonInstaller.cpp
	LinuxCliInstaller.cpp
	Service.cpp
	WinXpCliInstaller.cpp
	LinuxDaemonInstaller.cpp
	ServiceInstaller.cpp
	WinXpDaemonInstaller.cpp
	MacOsCliInstaller.cpp
	DaemonInstallersFactory.cpp
	CliInstallersFactory.cpp
	test.cpp
)

add_executable (patterns ${hdrs} ${srcs})

