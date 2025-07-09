#include "Span.hpp"

int main()
{
    Span sp = Span(10);
    try {
        // sp.setNumbers();
        sp.addNumber(30);
        sp.addNumber(0);
        sp.addNumber(17);
        sp.addNumber(433);
        sp.addNumber(9);
        sp.addNumber(103);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}