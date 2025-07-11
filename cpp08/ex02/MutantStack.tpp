#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other){}

template <typename T>
MutantStack& MutantStack<T>::operator=(const MutantStack& other)
{

    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return (*this);
}

template <typename T>
iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>
iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}