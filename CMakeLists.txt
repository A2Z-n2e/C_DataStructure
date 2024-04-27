cmake_minimum_required(VERSION 3.26)
#[[C && C++ 双语：“DataStructure C”改为“DataStructure LANGUAGES C CXX”]]
project(DataStructure LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
#[[add_executable(DataStructure main.c)]]

#[[数据结构初学]]
#[[add_executable(DataStructure Data_Structure/C/test.c)]]
#[[add_executable(DataStructure Data_Structure/CXX/test.cpp)]]
#[[线性表操作略写]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_a_SequenceList.c)]]
#[[线性表 - 参考]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_2.c)]]
#[[线性表 - 自行规范]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_2.c)]]
#[[线性表详细操作 - 参考]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_A.c)]]
#[[线性表详细操作 - 自行规范]]
add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_A_2.c)

#[[LeetCode做题]]
#[[add_executable(DataStructure LeetCode/C/test.c)]]
#[[add_executable(DataStructure LeetCode/CXX/test.cpp)]]

#[[add_executable(DataStructure Data_Structure/Structure/Func.c)]]
#[[add_executable(DataStructure Data_Structure/Structure/Func2.c)]]
