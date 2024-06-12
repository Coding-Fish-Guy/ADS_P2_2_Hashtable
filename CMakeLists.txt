cmake_minimum_required(VERSION 3.28)
project(ADS_P2_2_Hashtable)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADS_P2_2_Hashtable
        catch.h
        hashtable.cpp
        hashtable.h
        main.cpp
        unit_tests.cpp)
