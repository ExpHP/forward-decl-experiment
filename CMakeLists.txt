cmake_minimum_required(VERSION 3.8)
project(forwards)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/parse.cpp
        src/parse.hpp
        src/parse.tpp
        src/json.cpp
        src/json.hpp
        src/json-skel.hpp
        src/json-skel.tpp
        src/diagnostic/forward-dependency-cycle
        src/dummy.hpp
        )
add_executable(forwards ${SOURCE_FILES})