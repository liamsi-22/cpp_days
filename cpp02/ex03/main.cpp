#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    
    
    Point inside1(1.5, 1.5);
    Point inside2(1, 5);
    Point inside3(-1, -1);
    Point inside4(6, 0);
    Point inside5(0, 6);

    if (a.bsp(a, b, c, inside1))
        std::cout << "Point is inside the triangle." << std::endl;
    else
        std::cout << "Point is outside the triangle." << std::endl;
    
    if (a.bsp(a, b, c, inside2))
        std::cout << "Point is inside the triangle." << std::endl;
    else
        std::cout << "Point is outside the triangle." << std::endl;

    return 0;
}
