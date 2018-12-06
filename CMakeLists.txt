cmake_minimum_required(VERSION 3.12)
project(MathExpressions)

set(CMAKE_CXX_STANDARD 14)

set(MATH_EXP_PARSING
        #MathExpressionsParser
        Math_Expressions_Parsing/MathExpressionsParser.cpp Math_Expressions_Parsing/MathExpressionsParser.h
        #Factory
        Math_Expressions_Parsing/Factory.cpp Math_Expressions_Parsing/Factory.cpp)

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
        Plus.cpp Plus.h
        #Minus
        Minus.cpp Minus.h
        #Div
        Div.cpp Div.h
        #Mult
        Mult.cpp Mult.h)

add_executable(MathExpressions main.cpp ${SOURCE_FILES} ${UTILITIES} ${MATH_EXP_PARSING})