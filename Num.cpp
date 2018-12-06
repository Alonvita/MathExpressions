//
// Created by alon on 06/12/18.
//

#include "Num.h"

/**
 * Num(std::string str).
 */
Num::Num(std::string str) {
    this->value = stod(str);
}

/**
 * toString().
 *
 * @return a string representation of the expression
 */
std::string Num::toString() {
    std::ostringstream strs;
    strs << this->value;
    return strs.str();
}

/**
 * evaluate().
 *
 * @return the evaluated value of the expression.
 */
double Num::evaluate() {
    return this->value;
}

/// -------- OPERATORS OVERLOADING --------
/**
 * operator=().
 *
 * @param d double -- a double.
 * @return a reference to this Num after assignment.
 */
Num& Num::operator=(double d) {
    this->value = d;
    return *this;
}

/**
 * operator=().
 *
 * @param str const std::string& -- a const reference to a string.
 * @return a reference to this Num after assignment.
 */
Num& Num::operator=(const std::string& str) {
    this->value = stod(str);
}

/**
 * operator=().
 *
 * @param n const Num &  -- a const reference to another Num.
 *
 * @return a reference to this Num after assignment.
 */
Num& Num::operator=(const Num & n) {
    // copy num
    Num tmp = n;

    // copy val
    this->value = tmp.evaluate();
}