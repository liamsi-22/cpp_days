#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
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

void identify(Base* p){
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}


void identify(Base& p){
    try
    {
        A& a = dynamic_cast<A&>(p);
            std::cout << "A" << std::endl;
        (void)a;
    }
    catch(...){}
    try
    {
        B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        (void)b;
    }
    catch(...){}
    
    try
    {
        C& c = dynamic_cast<C&>(p);
            std::cout << "C" << std::endl;
        (void)c;
    }
    catch(...){}
}