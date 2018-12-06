//
// Created by alon on 06/12/18.
//

#include "BinaryExpression.h"

/**
 * evaluateBinExpression(BinExpressionEnum binaryExpression, double lhs, double rhs).
 *
 * @param operation BinExpressionEnum -- enum representing the operation
 * @param lhs double -- a double.
 * @param rhs double -- a double.
 *
 * @return lhs (OPERATION) rhs
 */
double BinaryExpression::evaluateBinExpression(BinaryOperation operation, double lhs, double rhs) {
    switch (operation) {
        case MINUS:
            return lhs - rhs;
        case PLUS:
            return lhs + rhs;
        case DIV:
            return lhs / rhs;
        case MULT:
            return lhs * rhs;
    }
}

/**
 * binExpressionToSTring(BinaryOperation operation).
 *
 * @param operation BinaryOperation -- an enum representing the Binary Operation.
 *
 * @return a string representing this BinaryExpression
 */
std::string BinaryExpression::binExpressionToString(BinaryOperation operation) {
    std::stringstream ss;

    ss << this->m_lhs->operator->()->toString();
    ss << opToString(operation);
    ss << this->m_rhs->operator->()->toString();

    return ss.str();
}

/**
 * opToString(BinaryOperation op)
 *
 * @param op BinaryOperation -- an enum representing the Binary Operation.
 *
 * @return a string representing this operation
 */
std::string BinaryExpression::opToString(BinaryOperation op) {
    switch (op) {
        case MINUS:
            return MINUS_STR;
        case PLUS:
            return PLUS_STR;
        case DIV:
            return DIV_STR;
        case MULT:
            return MULT_STR;
    }
}