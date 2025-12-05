#include "Span.hpp"

Span::Span():_max(0){}

Span::Span(unsigned int N):_max(N){}

Span::Span(const Span &other):_num_list(other._num_list), _max(other._max){}

Span &Span::operator=(const Span & other){
    if (this != &other)
    {
        _num_list = other._num_list;
        _max = other._max;
    }
    return(*this);
}

void Span::addNumber(int item){
    if (_num_list.size() >= _max)
        throw GenericExceptiton("Container is FULL!");
    _num_list.push_back(item);
}

int Span::shortestSpan() const{
    if (_num_list.size() < 2)
        throw GenericExceptiton("At least 2 items required!");
    std::vector<int> tmp = _num_list;
    std::sort(tmp.begin(), tmp.end());
    int mindiff = INT_MAX;
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < mindiff)
            mindiff = tmp[i + 1] - tmp[i];
    }
    return (mindiff);
}

int Span::longestSpan() const{
    if (_num_list.size() < 2)
        throw GenericExceptiton("At least 2 items required!");
    int min = *std::min_element(_num_list.begin(), _num_list.end());
    int max = *std::max_element(_num_list.begin(), _num_list.end());
    return (max - min);
}

Span::GenericExceptiton::GenericExceptiton(const std::string &str): _str(str){}

Span::GenericExceptiton::~GenericExceptiton() throw(){}

const char* Span::GenericExceptiton::what() const throw(){
    return _str.c_str();
}

Span::~Span(){}