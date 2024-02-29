cmake_minimum_required(VERSION 3.26)
#[[C && C++ 双语：“DataStructure C”改为“DataStructure LANGUAGES C CXX”]]
project(DataStructure LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
#[[add_executable(DataStructure main.c)]]

#[[add_executable(DataStructure Data_Structure/C/test.c)]]
#[[add_executable(DataStructure Data_Structure/CXX/test.cpp)]]

#[[add_executable(DataStructure LeetCode/C/test.c)]]
add_executable(DataStructure LeetCode/CXX/test.cpp)