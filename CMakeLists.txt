cmake_minimum_required(VERSION 3.12)
project(MathExpressions)

set(CMAKE_CXX_STANDARD 14)

set(UTILITIES
        #ReferenceCounting
        Reference_Counting/ReferenceCount.h
        #SmartPtr
        Reference_Counting/SmartPtr.h)

set(SOURCE_FILES
        #Expression
        Expression.h
        #Num
        Num.cpp Num.h
        #BinaryExpression
        BinaryExpression.cpp BinaryExpression.h
        #Plus
        Plus.cpp Plus.h)

add_executable(MathExpressions main.cpp ${SOURCE_FILES} ${UTILITIES})