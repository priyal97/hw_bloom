cmake_minimum_required(VERSION 3.6)
project(hw4bloomBackEnd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp myBloom.cpp myBloom.h Bloom.h)
add_executable(hw4BloomFilter ${SOURCE_FILES})