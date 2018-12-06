//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_BINARYEXPRESSION_H
#define MATHEXPRESSIONS_BINARYEXPRESSION_H


#include "Expression.h"
#include "Reference_Counting/SmartPtr.h"

class BinaryExpression : Expression {


private:
    smart_ptr<Expression> lhs;
    smart_ptr<Expression> rhs;
};


#endif //MATHEXPRESSIONS_BINARYEXPRESSION_H
