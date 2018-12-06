//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_BINARYEXPRESSION_H
#define MATHEXPRESSIONS_BINARYEXPRESSION_H

#include "Num.h"
#include "Expression.h"
#include "Reference_Counting/SmartPtr.h"

class BinaryExpression : public Expression {
public:
    BinaryExpression(smart_ptr<Expression>* lhs, smart_ptr<Expression>* rhs) : m_rhs(rhs), m_lhs(lhs) {};


protected:
    double evaluateBinExpression(BinaryOperation operation, double lhs, double rhs);
    std::string binExpressionToString(BinaryOperation operation);

    smart_ptr<Expression>* m_lhs;
    smart_ptr<Expression>* m_rhs;

private:
    std::string opToString(BinaryOperation op);
};


#endif //MATHEXPRESSIONS_BINARYEXPRESSION_H
