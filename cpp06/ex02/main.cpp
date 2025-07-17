#include <iostream>
#include "Base.hpp"
#include "assert.h"

int main(){
    srand(time(0));
    Base *b = generate();

    identify(*b);
    identify(b);

    delete b;
    return (0);
}

