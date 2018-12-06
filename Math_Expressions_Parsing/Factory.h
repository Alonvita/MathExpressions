//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_FACTORY_H
#define MATHEXPRESSIONS_FACTORY_H


#include "../Expression.h"
#include "../Reference_Counting/SmartPtr.h"

class Factory {
    Factory() = default;

    smart_ptr<Expression>* createNum(std::string val);
    smart_ptr<Expression>* createExpression(BinaryOperation op,
                                            smart_ptr<Expression>* lhs,
                                            smart_ptr<Expression>* rhs);

    smart_ptr<Expression>* createExpression(UnaryOperation op); // Will not be used in this code, but may be added and modified
};


#endif //MATHEXPRESSIONS_FACTORY_H
