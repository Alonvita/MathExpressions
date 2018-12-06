//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_NUM_H
#define MATHEXPRESSIONS_NUM_H


#include "Expression.h"

class Num : public Expression {
public:
    Num(std::string);
    Num(double number) : value(number) {};

    double evaluate() override;
    std::string toString() override;
private:
    double value;
};


#endif //MATHEXPRESSIONS_NUM_H
