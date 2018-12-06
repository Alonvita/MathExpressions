//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_PARSER_H
#define MATHEXPRESSIONS_PARSER_H


#include <list>
#include <string>
#include <iterator>
#include "../Expression.h"
#include "../Reference_Counting/SmartPtr.h"

#define MATH_EXPRESSION_DELIMITERS "+-*/)("

class MathExpressionsParser {
public:
    MathExpressionsParser() = default;

    smart_ptr<Expression>* parse_mathematical_expression(const std::string &rawExpression);

private:
    ///---------- UTILITY FUNCTIONS ----------
    bool isOperand(const std::string& str);
    bool isOperator(const std::string& str);
    bool isParenthases(const std::string& str);
    std::list<std::string>& prefixToPostFix(const std::list<std::string> mathExpressionAsList);
    std::list<std::string> splitString(const std::string &input, const std::string &delimiterStr, bool keepSpaces, bool keepDelimiters);
    void splitStringToList(const std::string &input, const std::string& delimiterStr, std::list<std::string> &outList, bool keepDelimiters);
};


#endif //MATHEXPRESSIONS_PARSER_H
