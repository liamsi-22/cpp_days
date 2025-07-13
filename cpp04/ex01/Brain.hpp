#ifndef BRAIN_HPP
#define BRAIN_HPP

#define BRAIN_SIZE 100

#include <iostream>
#include <string>

class Brain{
    protected:
        std::string ideas[BRAIN_SIZE];

    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();
};

#endif