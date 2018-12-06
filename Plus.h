//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_PLUS_H
#define MATHEXPRESSIONS_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(double, double);
    Plus(const std::string&, const std::string&);
    Plus(smart_ptr<Expression>* lhs, smart_ptr<Expression>* rhs) : BinaryExpression(lhs, rhs) {};

    double evaluate() override;
    std::string toString() override;
};


#endif //MATHEXPRESSIONS_PLUS_H
