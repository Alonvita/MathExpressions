#include <iostream>
#include "Num.h"
#include "Plus.h"

int main() {
    smart_ptr<Expression> smrt1(new Num("125"));
    smart_ptr<Expression> smrt2(new Num("12"));

    smart_ptr<Expression> p_smrt_ptr(new Plus(&smrt1, &smrt2));

    //double val = p_smrt_ptr->evaluate();
    //std::cout << p_smrt_ptr->toString() << ": " << val << "\n";
}

