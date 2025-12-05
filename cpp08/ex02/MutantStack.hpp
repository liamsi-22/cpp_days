#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>

template  <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T>& other);
        MutantStack<T>& operator=(const MutantStack<T>& other);

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();

        ~MutantStack();
};

#include "MutantStack.tpp"

#endif