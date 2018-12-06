//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_EXPRESSION_H
#define MATHEXPRESSIONS_EXPRESSION_H

#include <string>
#include <sstream>

class Expression {
public:
    virtual std::string toString() = 0;
    virtual double evaluate() = 0;
};

#endif //MATHEXPRESSIONS_EXPRESSION_H
