//
// Created by alon on 06/12/18.
//

#include "Factory.h"
#include "../Reference_Counting/SmartPtr.h"
#include "../Num.h"


/**
 * createExpression(BinaryOperation op)
 *
 * @param op
 * @return
 */
smart_ptr<Expression>* Factory::createExpression(BinaryOperation op,
                                                 smart_ptr<Expression>* lhs,
                                                 smart_ptr<Expression>* rhs) {


}

/**
 * createNum(double val).
 *
 * @param val std::string -- a string representing a double value
 * @return
 */
smart_ptr<Expression>* Factory::createNum(std::string val) {
   return new smart_ptr<Expression>(new Num(stod(val)));
}