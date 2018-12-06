//
// Created by alon on 06/12/18.
//

#include <vector>
#include "MathExpressionsParser.h"

/**
 * parse(std::string rawExpression).
 *
 * @param rawExpression std::string -- a string representing a mathematical expression.
 *
 * @return an Expression created from the given string.
 */
smart_ptr<Expression>* MathExpressionsParser::parse_mathematical_expression(const std::string &rawExpression) {
        // split the string into a list w/o spaces and keep delimiters (see function documentation for more info)
    std::list<std::string> expressionAsList =
            splitString(rawExpression, MATH_EXPRESSION_DELIMITERS, false, true);


//    While (we have not reached the end of Q)
//    If (an operand is found)
//    Add it to P
//    End-If
//    If (a left parenthesis is found)
//    Push it onto the stack
//    End-If
//    If (a right parenthesis is found)
//    While (the stack is not empty AND the top item is
//    not a left parenthesis)
//    Pop the stack and add the popped value to P
//    End-While
//    Pop the left parenthesis from the stack and discard it
//    End-If
//    If (an operator is found)
//    If (the stack is empty or if the top element is a left
//    parenthesis)
//    Push the operator onto the stack
//    Else
//    While (the stack is not empty AND the top of the stack
//    is not a left parenthesis AND precedence of the
//    operator <= precedence of the top of the stack)
//    Pop the stack and add the top value to P
//    End-While
//    Push the latest operator onto the stack
//    End-If
//    End-If
//    End-While
//    While (the stack is not empty)
//    Pop the stack and add the popped value to P
//    End-While


}

///---------- UTILITY FUNCTIONS ----------

/**
 * isOperand(std::string str).
 *
 * @param str
 * @return
 */
bool MathExpressionsParser::isOperand(const std::string& str) {
    return false;
}

/**
 * splitStringToList(const std::string &inStr, const std::string& delimiterStr, std::list<std::string> &outList).
 *
 * @param input const std::string & -- the input string.
 * @param delimiterStr const std::string & -- all of the delimiters that you can think of.
 * @param outList std::list<std::string> & -- the output list to modify.
 * @param keepDelimiters bool -- true return a list with the delimiters, or false otherwise.
 *
 */

void MathExpressionsParser::splitStringToList(const std::string &input, const std::string& delimiterStr, std::list<std::string> &outList, bool keepDelimiters) {
    // Local Variables
    size_t found, token = 0;
    found = input.find_first_of(delimiterStr); // find the first char in the string that meats any of the separators

    // Run over the string
    while (found != string::npos) {
        // push the substring to outList
        outList.push_back(input.substr(token, found - token));
        if(keepDelimiters)
            outList.push_back(input.substr(found, 1));
        // token <- found + 1 (advance token)
        token = found + 1;
        // run the search again
        found = input.find_first_of(delimiterStr, token);
    }

    // push the rest of the string
    outList.push_back(input.substr(token, found - token));
}

/**
 * splitString(const std::string &inStr, const std::string &sepStr, bool keepSpaces).
 *
 * @param input const std::string & -- the string to parse.
 * @param delimiterStr const std::string & -- all of the delimiters you can think off.
 * @param keepSpaces bool -- true return a list with white spaces, or false otherwise.
 * @param keepDelimiters bool -- true return a list with the delimiters, or false otherwise.
 *
 * @return the parsed string as list, with or withour white spaces.
 */
std::list<std::string> MathExpressionsParser::splitString(const std::string &input, const std::string &delimiterStr, bool keepSpaces, bool keepDelimiters) {
    // Local Variables
    std::list<std::string> output, splitOutput;

    // call split
    splitStringToList(input, delimiterStr, splitOutput, keepDelimiters);

    if (keepSpaces) {
        output = splitOutput;
    } else {
        for (std::string str : splitOutput) {
            if (str.length() > 0) {
                output.push_back(str);
            }
        }
    }

    return output;
}