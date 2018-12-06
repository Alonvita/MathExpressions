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