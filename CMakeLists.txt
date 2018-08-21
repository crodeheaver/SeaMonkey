cmake_minimum_required(VERSION 3.12)
project(SeaLion C)

set(CMAKE_C_STANDARD 11)

add_executable(SeaLion main.c includes/token.h includes/lexer.h src/lexer.c src/token.c)