cmake_minimum_required(VERSION 3.19)
project(Library_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library_System main.cpp User.cpp User.h UserList.cpp UserList.h Book.cpp Book.h BookList.cpp BookList.h)