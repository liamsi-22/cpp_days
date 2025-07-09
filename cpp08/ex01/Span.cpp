#include "Span.hpp"

Span::Span(){
        std::cout << "constructor is being called" << std::endl;
        std::srand(std::time(nullptr));
}

Span::Span(unsigned int n): _max(n){
    std::cout << "parametirize constructor is being called" << std::endl;
    std::srand(std::time(nullptr));
}

Span::Span(const Span& other): _max(other._max), _numbers(other._numbers){}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _max =  other._max;
        _numbers = other._numbers;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _max)
        throw ReachMaxnumber();
    _numbers.push_back(n);
}

int Span::shortestSpan() const{
    if (_numbers.size() < 2)
        throw NotEnoughNumbers();
    std::vector<int> sorted_array = _numbers;
    std::sort(sorted_array.begin(), sorted_array.end());

    int smallSpan = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = sorted_array.begin(); (it + 1) != sorted_array.end(); ++it)
    {
        int diff = *(it + 1) - *it;
        if (diff < smallSpan)
            smallSpan = diff;
    }
    return (smallSpan);
}

int Span::longestSpan() const{
    if (_numbers.size() < 2)
        throw NotEnoughNumbers();
    int max = *std::max_element(_numbers.begin(),_numbers.end());
    int min = *std::min_element(_numbers.begin(),_numbers.end());
    return (std::abs(max - min));
}


void Span::setNumbers(){
    for (int i = 0; i < _max; ++i)
    {
        int random = std::rand() % 10000;
        Span::addNumber(random);
    }
}

const char* Span::ReachMaxnumber::what() const throw() {
    return ("ERROR:\tno more space left in the container !");
}

const char* Span::NotEnoughNumbers::what() const throw() {
    return ("ERROR:\tnot enoguh numbers in the container !");
}

Span::~Span(){
    std::cout << "destructor is being called" << std::endl;
}
