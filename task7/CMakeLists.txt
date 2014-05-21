cmake_minimum_required(VERSION 2.8)
project (wyznacz_droge)

set (hdrs
	Node.h
	Grid.h
)

set (srcs
	Node.cpp
	Grid.cpp
	main.cpp
)

add_executable (wyznacz_droge ${hdrs} ${srcs})

