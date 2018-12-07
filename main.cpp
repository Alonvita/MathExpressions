#include <iostream>
#include <vector>
#include "Math_Expressions_Parsing/MathExpressionsParser.h"

using namespace std;

int main() {
    std::string test = "((2 + 5 * 22) * 19 - y) ";
    std::string checks = "+-)(*/";

    map<std::string, double> variablesMap;


    variablesMap.insert(make_pair("x", 15));
    variablesMap.insert(make_pair("y", 10));
    variablesMap.insert(make_pair("z", 50));
    variablesMap.insert(make_pair("w", 49));

    MathExpressionsParser parser;
    cout << "----- (MAIN) DEBUG: CHECK EVALUATION START -----";
    cout << "\n" << parser.parse_mathematical_expression(test, variablesMap)<< "\n";
    cout << " ----- (MAIN) DEBUG: CHECK EVALUATION END -----\n";
}