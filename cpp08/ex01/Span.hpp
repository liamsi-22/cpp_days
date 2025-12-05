#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <climits>
#include <exception>
#include <algorithm>

class Span
{
    private:
        std::vector<int> _num_list;
        unsigned int _max;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span & other);
        Span &operator=(const Span & other);

        void addNumber(int item);
        int shortestSpan() const;
        int longestSpan() const;

        class GenericExceptiton : public std::exception
        {
            private:
                std::string _str;
            public :
                GenericExceptiton(const std::string &str);
                const char* what() const throw();
                ~GenericExceptiton() throw();
        };
        
        template <typename Input_It>
        void addNumbers(Input_It begin, Input_It end);
        ~Span();
};

template <typename Input_It>
void Span::addNumbers(Input_It begin, Input_It end) {
    if (_num_list.size() + std::distance(begin, end) > _max)
        throw GenericExceptiton("Container is FULL!");

    _num_list.insert(_num_list.end(), begin, end);
}

#endif