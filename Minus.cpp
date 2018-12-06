//
// Created by alon on 06/12/18.
//

#include "Minus.h"

/**
 * evaluate().
 *
 * @return the evaluated value of the expression.
 */
double Minus::evaluate() {
    return (evaluateBinExpression(
            MINUS,
            this->m_lhs->operator->()->evaluate(),
            this->m_rhs->operator->()->evaluate()));
}

/**
 * toString().
 *
 * @return a string representation of the expression
 */
std::string Minus::toString() {
    return binExpressionToString(MINUS);
}