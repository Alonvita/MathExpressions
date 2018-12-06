#include <iostream>
#include <vector>
#include "Num.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Math_Expressions_Parsing/MathExpressionsParser.h"

using namespace std;

int main() {
    /*smart_ptr<Expression> smrt1(new Num("1000"));
    smart_ptr<Expression> smrt2(new Num("500"));

    smart_ptr<Expression> p_smrt_ptr(new Minus(&smrt1, &smrt2));

    smart_ptr<Expression> smrt3(new Num("49"));
    smart_ptr<Expression> smrt4(new Num("-7"));

    smart_ptr<Expression> p_smrt_ptr2(new Div(&smrt3, &smrt4));

    smart_ptr<Expression> p_smrt_ptr3(new Mult(&p_smrt_ptr, &p_smrt_ptr2));

    double val = p_smrt_ptr3->evaluate();
    std::cout << p_smrt_ptr3->toString() << ": " << val << "\n";



    parser.parse_mathematical_expression("(x+532)-y\n");*/

    std::string test = "((2x + 5 * 22) * 19 - hammond) ";
    std::string checks = "+-)(*/";


    MathExpressionsParser parser;
    parser.parse_mathematical_expression(test);
}