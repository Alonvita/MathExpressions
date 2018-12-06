cmake_minimum_required(VERSION 3.12)
project(MathExpressions)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        #Expression
        Expression.h
        #Num
        Num.cpp Num.h)

add_executable(MathExpressions main.cpp ${SOURCE_FILES})