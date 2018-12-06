#include <iostream>
#include "Num.h"
#include "Plus.h"
#include "Minus.h"

int main() {
    smart_ptr<Expression> smrt1(new Num("125"));
    smart_ptr<Expression> smrt2(new Num("1212"));

    smart_ptr<Expression> p_smrt_ptr(new Minus(&smrt1, &smrt2));

    smart_ptr<Expression> smrt3(new Num("1090"));
    smart_ptr<Expression> smrt4(new Num("-3"));

    smart_ptr<Expression> p_smrt_ptr2(new Minus(&smrt1, &smrt2));

    smart_ptr<Expression> p_smrt_ptr3(new Minus(&p_smrt_ptr, &p_smrt_ptr2));

    double val = p_smrt_ptr3->evaluate();
    std::cout << p_smrt_ptr3->toString() << ": " << val << "\n";
}

