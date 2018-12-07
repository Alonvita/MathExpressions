cmake_minimum_required(VERSION 3.12)
project(MathExpressions)

set(CMAKE_CXX_STANDARD 14)

set(MATH_EXP_PARSING
        #MathExpressionsParser
        Math_Expressions_Parsing/MathExpressionsParser.cpp Math_Expressions_Parsing/MathExpressionsParser.h)

set(UTILITIES
        #ReferenceCounting
        Reference_Counting/ReferenceCount.h
        #SmartPtr
        Reference_Counting/SmartPtr.h
        #Utility
        Utility/UtilityFunctions.cpp Utility/UtilityFunctions.h)

add_executable(MathExpressions main.cpp ${UTILITIES} ${MATH_EXP_PARSING})