cmake_minimum_required(VERSION 3.20)
project(Hangman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hangman main.cpp Game.cpp Game.h)
