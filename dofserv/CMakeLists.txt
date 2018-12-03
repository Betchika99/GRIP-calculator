cmake_minimum_required(VERSION 3.9)
project(DofServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        DofServer
        json_parser.hpp
        json_parser.cpp
        handler.hpp
        handler.cpp
        main.cpp
)

target_link_libraries(DofServer event jansson mongotest libmongoc libmongocxx libbson)
