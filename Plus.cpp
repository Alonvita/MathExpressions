//
// Created by alon on 06/12/18.
//

#include "Plus.h"
//
///**
// * Plus(double lhs, double rhs).
// *
// * @param lhs double -- a double.
// * @param rhs double -- a double.
// */
//Plus::Plus(double lhs, double rhs) :
//    Plus(smart_ptr<Expression> (new Num(lhs)),
//         smart_ptr<Expression> (new Num(rhs))) {};
//
///**
// * Plus(const std::string& lhs, const std::string& rhs).
// *
// * @param lhs
// * @param rhs
// */
//Plus::Plus(const std::string& lhs, const std::string& rhs) :
//        Plus(smart_ptr<Expression> (new Num(lhs)),
//             smart_ptr<Expression> (new Num(rhs))) {};

/**
 * evaluate().
 *
 * @return the evaluated value of the expression.
 */
double Plus::evaluate() {
    return (
            this->m_lhs->operator->()->evaluate() +
            this->m_rhs->operator->()->evaluate());
}

/**
 * toString().
 *
 * @return a string representation of the expression
 */
std::string Plus::toString() {
    std::stringstream ss;

    ss << this->m_lhs->operator->()->toString();
    ss << PLUS;
    ss << this->m_rhs->operator->()->toString();

    return ss.str();
}