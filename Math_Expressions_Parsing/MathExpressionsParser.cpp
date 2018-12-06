//
// Created by alon on 06/12/18.
//

#include <vector>
#include <algorithm>
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
            splitString(rawExpression, DELIMITERS, false, true);

    // strip from trailing spaces
    for(std::string& str : expressionAsList) {
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
    }

    // TODO: DEBUG: print expression -> remove this
    printExpression(expressionAsList);

    std::list<std::string> expressionAsPostFix;
    prefixToPostFix(expressionAsList, expressionAsPostFix);

    // TODO: DEBUG: print expression -> remove this
    printExpression(expressionAsPostFix);
    return nullptr;
}

///---------- UTILITY FUNCTIONS ----------

/**
 * prefixToPostFix(const std::list<std::string> mathExpressionAsList).
 *
 * @param mathExpressionAsList const std::list<std::string>& -- a constant reference to a
 *                                                              list<string> representing a prefix math expression.
 * @param postfix std::list<std::string>& -- the list to modify.
 *
 * Pseudo source: http://faculty.cs.niu.edu/~hutchins/csci241/eval.htm
 */
void MathExpressionsParser::prefixToPostFix(
        const std::list<std::string>& mathExpressionAsList,
        std::list<std::string>& postfix) {
    stack<std::string> stack;

    // iterate over the list
    for(std::string str : mathExpressionAsList) {
        // if "(" -> add to stack
        if(isLeftParentheses(str)) {
            stack.push(str);
            continue;
        }

        // if ")"
        if(isRightParentheses(str)) {
            // while stack not empty AND not "("
            while(!stack.empty() && !isLeftParentheses(stack.top())) {
                postfix.push_back(stack.top()); // add to postfix
                stack.pop(); // remove
            }
            stack.pop(); // pop the "("
            continue;
        }

        // if operator
        if(isOperator(str)) {
            // if stack is empty or top item is "("
            if(stack.empty() || isLeftParentheses(stack.top())) {
                stack.push(str); // push it to the stack
            } else {
                while(!stack.empty() &&
                      !isLeftParentheses(stack.top()) &&
                      precedence(str) <= precedence(stack.top())) {
                    // pop and push to the postfix expression
                    postfix.push_back(stack.top());
                    stack.pop();
                }
                // push the operator to the stack
                stack.push(str);
            }
            continue;
        }
        // reaching here means that all "ifs" failed, and this is a variable or a number
        postfix.push_back(str);
    }

    while(!stack.empty()) {
        postfix.push_back(stack.top());
        stack.pop();
    }
}

/**
 * precedence(const std::string &op).
 *
 * @param op const std::string -- a constant string representing an operator;
 *
 * @return the precedence of the operator as an integer as follows:
 *      -,+          : LOW_PRECEDENCE
 *      *,/,%        : MEDIUM_PRECEDENCE
 *      pow,root,abs : HIGH_PRECEDENCE
 *      other        : PRECEDENCE_ERROR
 */
int MathExpressionsParser::precedence(const std::string &op) {
    if(op == MINUS_STR || op == PLUS_STR)
        return LOW_PRECEDENCE;

    if(op == MULT_STR || op == DIV_STR || op == MODULO_STR)
        return MEDIUM_PRECEDENCE;

    if(op == ROOT_STR || op == POW_STR || op == ABS_STR)
        return HIGH_PRECEDENCE;

    return PRECEDENCE_ERROR;
}

/**
 * isOperand(std::string str).
 *
 * @param str const std::string& -- a reference to a string.
 *
 * @return true if the string contains only digits. Hence, a number
 */
bool MathExpressionsParser::isNumeric(const std::string &str) {
    return ((str.end() ==
             std::find_if(
                     str.begin(),
                     str.end(),
                     [](unsigned char c)->bool { return !isdigit(c); })));
}

/**
 * isOperator(const std::string &str).
 *
 * @param str const std::string& -- a reference to a constant string.
 *
 * @return true if the string is an operand, or false otherwise.
 */
bool MathExpressionsParser::isOperator(const std::string &str) {
   return(str.find_first_of(OPERATORS) != str.npos);
}

/**
 * isLeftParentheses(const std::string &str).
 *
 * @param str const std::string& -- a reference to a constant string.
 *
 * @return true if the string is "(", or false oterwise.
 */
bool MathExpressionsParser::isLeftParentheses(const std::string &str) {
    return (str == "(");
}

/**
 * isRightParentheses(const std::string &str).
 *
 * @param str const std::string& -- a reference to a constant string.
 *
 * @return true if the string is ")", or false oterwise.
 */
bool MathExpressionsParser::isRightParentheses(const std::string &str) {
    return (str == ")");
}

/**
 * getStrLocationInMap(const std::string &str, map<Num, double> variablesMap).
 *
 * @param str const std::string & -- a reference to a constant string.
 * @param variablesMap map<std::string, Num> -- a map of name->variable
 *
 * @return the iterator location to the string in the map (map.end() if doesn't exist).
 */
map<std::string, Num>::iterator
    MathExpressionsParser::getStrLocationInMap(const std::string &str, map<std::string, Num> variablesMap) {
    return variablesMap.find(str);
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
            if (str.length() > 0 && str != " ") {
                output.push_back(str);
            }
        }
    }

    return output;
}

///---------- DEBUGGING ----------
/**
 * printExpression(const std::list<std::string> &exp).
 *
 * @param exp const std::list<std::string> & -- a list<string. representing a mathematical expression
 */
void MathExpressionsParser::printExpression(const std::list<std::string> &exp) {
    cout << "\n\n---- Expression Print Check BEGIN ---- \n";
    for(std::string s : exp)
        cout << s << " ";
    cout << "\n";
    cout << "---- Expression Print Check END ---- \n";
}