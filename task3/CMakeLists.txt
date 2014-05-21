cmake_minimum_required(VERSION 2.8)
project (base_converter)

set (hdrs
	BaseConverter.h
)

set (srcs
	BaseConverter.cpp
	test.cpp
)

add_executable (base_converter ${hdrs} ${srcs})

