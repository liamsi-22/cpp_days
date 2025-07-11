#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);

        iterator begin();
        iterator end();

        ~MutantStack();
};

#include "MutantStack.tpp"