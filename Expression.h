//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_EXPRESSION_H
#define MATHEXPRESSIONS_EXPRESSION_H

#include <string>
#include <sstream>

#define DIV_STR "/"
#define PLUS_STR "+"
#define MULT_STR "*"
#define MINUS_STR "-"
#define MODULO_STR "%"

#define ABS_STR "abs"
#define POW_STR "pow"
#define ROOT_STR "root"

enum UnaryOperation { SIN , COS, TAN, ABS, LOG };
enum BinaryOperation { MINUS, PLUS, DIV, MULT };

class Expression {
public:
    virtual double evaluate() = 0 ;
    virtual std::string toString() = 0;
};

#endif //MATHEXPRESSIONS_EXPRESSION_H
