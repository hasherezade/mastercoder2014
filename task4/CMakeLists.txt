cmake_minimum_required(VERSION 2.8)
project (czarnobyl)

set (hdrs
	Walls.h
)

set (srcs
	Walls.cpp
	main.cpp
)

add_executable (czarnobyl ${hdrs} ${srcs})

