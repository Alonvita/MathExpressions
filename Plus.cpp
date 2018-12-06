//
// Created by alon on 06/12/18.
//

#include "Plus.h"

/**
 * evaluate().
 *
 * @return the evaluated value of the expression.
 */
double Plus::evaluate() {
    return(evaluateBinExpression(
            PLUS,
            this->m_lhs->operator->()->evaluate(),
            this->m_rhs->operator->()->evaluate()));
}

/**
 * toString().
 *
 * @return a string representation of the expression
 */
std::string Plus::toString() {
    return binExpressionToString(PLUS);
}