#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <ctime>

class Span
{
    private:
        unsigned int _max;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
        void setNumbers();
        
        class ReachMaxnumber : public std::exception{
            public :
                const char* what() const throw();
        };

        class NotEnoughNumbers : public std::exception{
            public :
                const char* what() const throw();
        };


    ~Span();
};

