#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    srand(time(0));
    int x = 1 + (rand() % 3);
    switch (x)
    {
        case 1 :
            return new A();
        case 2 :
            return new B();
        case 3 :
            return new C();
        default :
        return NULL;
    }
}

// It only works properly when:
// The base class has at least one virtual function (usually a virtual destructor).
// The cast is between polymorphic types.

void identify(Base* p){
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Because references in C++ can’t be null — they must always bind to a valid object. So there's no safe "null" fallback like with pointers, hence the exception.


void identify(Base& p){
    try
    {
        A& a = dynamic_cast<A&>(p);
            std::cout << "A" << std::endl;
    }
    catch(...){}

    try
    {
        B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
    }
    catch(...){}
    
    try
    {
        C& a = dynamic_cast<C&>(p);
            std::cout << "C" << std::endl;
    }
    catch(...){}
}