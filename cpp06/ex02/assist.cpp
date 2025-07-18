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



//  Under the Hood: What Happens?
// When you use dynamic_cast, the compiler relies on RTTI (Run-Time Type Information) to check whether the cast is valid at runtime.

// Here's the general process:

// 1. Vtable and RTTI Setup
// When you have a class with virtual functions (like a virtual destructor), the compiler:

// Creates a vtable for that class.

// Associates the object with a vptr (virtual pointer) pointing to the vtable.

// Embeds RTTI metadata in the vtable (including type name and inheritance info).

// 2. Casting Process
// When you call dynamic_cast<Derived*>(basePtr):

// The program looks at the RTTI information in the vtable of the actual object pointed to by basePtr.

// It checks whether the type has a valid relationship to Derived (i.e., it’s really pointing to a Derived object or something that inherits from Derived).

// If it's valid:

// It calculates the correct offset (in memory) to convert the Base* to a Derived*.

// Returns the pointer.

// If it's invalid:

// For pointer casts: returns nullptr.

// For reference casts: throws std::bad_cast.


// !!!! dynamic_cast<> isn't free: it incurs runtime overhead due to RTTI lookup and vtable traversal.
// Needs	Base class with virtual function (for vtable/RTTI setup)