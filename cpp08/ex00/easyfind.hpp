#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <string>

class My_exception : public std::exception
{
    private:
        std::string _msg;
    public:
        My_exception(const std::string &msg);
        const char *what() const throw();
        ~My_exception() throw();
};


template <typename T>
typename T::iterator easyfind(T &container, int value);


#include "easyfind.tpp"

#endif