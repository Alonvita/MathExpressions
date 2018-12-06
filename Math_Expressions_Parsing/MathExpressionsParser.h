//
// Created by alon on 06/12/18.
//

#ifndef MATHEXPRESSIONS_PARSER_H
#define MATHEXPRESSIONS_PARSER_H

#include <map>
#include <list>
#include <stack>
#include <string>
#include <iterator>

#include "../Num.h"
#include "../Expression.h"
#include "../Utility/UtilityFunctions.h"
#include "../Reference_Counting/SmartPtr.h"

#define DELIMITERS "+-*/)("
#define OPERATORS "+-*/"

#define PRECEDENCE_ERROR -1
#define LOW_PRECEDENCE 3
#define MEDIUM_PRECEDENCE 4
#define HIGH_PRECEDENCE 5

class MathExpressionsParser {
public:
    MathExpressionsParser() = default;

    smart_ptr<Expression>* parse_mathematical_expression(const std::string &rawExpression);

private:
    ///---------- UTILITY FUNCTIONS ----------
    int precedence(const std::string& opL);
    bool isNumeric(const std::string &str);
    bool isOperator(const std::string& str);
    bool isLeftParentheses(const std::string &str);
    bool isRightParentheses(const std::string &str);
    void prefixToPostFix(const std::list<std::string>& mathExpressionAsList, std::list<std::string>& postfix);
    map<std::string, Num>::iterator getStrLocationInMap(const std::string &str, map<std::string, Num> variablesMap);
    std::list<std::string> splitString(const std::string &input, const std::string &delimiterStr, bool keepSpaces, bool keepDelimiters);
    void splitStringToList(const std::string &input, const std::string& delimiterStr, std::list<std::string> &outList, bool keepDelimiters);
    smart_ptr<Expression>* createExpressionFromPostFixList(const std::list<std::string>& postfixExpression, const map<std::string, Num>& variablesMap);

    ///---------- DEBUGGING ----------
    void printExpression(const std::list<std::string>& exp);
};


#endif //MATHEXPRESSIONS_PARSER_H
