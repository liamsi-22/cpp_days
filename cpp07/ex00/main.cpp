#include "whatever.hpp"



int main(){
    int x = 90;
    int y = 65;

    std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
    std::cout << ::min(x,y) << std::endl;
    std::cout << ::max(x,y) << std::endl;
    ::swap(x,y);
    std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
    std::cout << ::min(x,y) << std::endl;
    std::cout << ::max(x,y) << std::endl;
    ::swap(x,y);
    std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
}

// int main( void ) {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }



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