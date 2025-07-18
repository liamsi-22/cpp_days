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


