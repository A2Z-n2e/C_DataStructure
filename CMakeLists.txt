cmake_minimum_required(VERSION 3.26)
#[[C && C++ 双语：“DataStructure C”改为“DataStructure LANGUAGES C CXX”]]
project(DataStructure LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
#[[add_executable(DataStructure main.c)]]

#[[数据结构初学]]
#[[add_executable(DataStructure Data_Structure/C/test.c)]]
#[[add_executable(DataStructure Data_Structure/CXX/test.cpp)]]
#[[线性表略写]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_a_SequenceList.c)]]
#[[线性表 - 参考]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList.c)]]
#[[线性表 - 自行规范]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_2.c)]]
#[[线性表详细操作 - 参考]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_A.c
        Data_Structure/C/LinearList/test.c)]]
#[[线性表详细操作 - 自行规范]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/2.1_SequenceList_A_2.c)]]
#[[add_executable(DataStructure Data_Structure/C/LinearList/test.cpp)]]







#[[2.1 线性表 - 操作略写]]
#[[add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.1_a_SequenceList.cpp)]]
#[[2.1 线性表 - 操作详情 - 静态数组]]
#[[add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.1_SequenceList_1.cpp)]]
#[[2.1 线性表 - 操作详情 - 动态数组]]
#[[add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.1_SequenceList_2.cpp)]]
#[[2.2 单链表 - 无操作略写]]
#[[add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.2_a_SingleLinkedList.cpp)]]
#[[2.2 单链表 - 操作详情 - 带头结点]]
add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.2_SingleLinkedList_1.cpp)
#[[2.2 单链表 - 操作详情 - 不带头结点]]
#[[add_executable(DataStructure Data_Structure/CXX/C2_LinearList/2.2_SingleLinkedList_2.cpp)]]







#[[LeetCode做题]]
#[[add_executable(DataStructure LeetCode/C/test.c)]]
#[[add_executable(DataStructure LeetCode/CXX/test.cpp)]]

#[[add_executable(DataStructure Data_Structure/Structure/Func.c)]]
#[[add_executable(DataStructure Data_Structure/Structure/Func2.c)]]
