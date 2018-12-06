//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_MINUS_H
#define MATHEXPRESSIONS_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(smart_ptr<Expression>* lhs, smart_ptr<Expression>* rhs) : BinaryExpression(lhs, rhs) {};

    double evaluate() override;
    std::string toString() override;
};


#endif //MATHEXPRESSIONS_MINUS_H
