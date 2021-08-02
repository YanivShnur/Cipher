cmake_minimum_required(VERSION 3.20)
project(Cipher)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cipher main.cpp CaesarCipher.h CaesarCipher.cpp)
