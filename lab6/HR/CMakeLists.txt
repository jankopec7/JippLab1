
cmake_minimum_required(VERSION 3.10)
project(HR)

set(CMAKE_CXX_STANDARD 17)


include_directories(./include ./src)
add_executable(zadanie ./src/main.cpp ./src/hrms.cpp ./src/employee.cpp)