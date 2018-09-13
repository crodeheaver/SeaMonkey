cmake_minimum_required(VERSION 3.10)
project(SeaMonkey)

set(CMAKE_CXX_STANDARD 11)

add_executable(SeaMonkey main.cpp includes/token.h includes/lexer.h includes/tokens.h includes/interfaces.h includes/program.h src/lexer.cpp src/token.cpp)

configure_file(myfile.mky ./myfile.mky COPYONLY)