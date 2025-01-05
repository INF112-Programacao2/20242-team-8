cmake_minimum_required(VERSION 3.30)
project(ProjetoFinal)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetoFinal main.cpp
        DatabaseConnection.cpp
        DatabaseConnection.h)
