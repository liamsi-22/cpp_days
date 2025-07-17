#include "Data.hpp"


Data::Data(){}

Data::Data(int val): value(val){}

Data::Data(const Data& other): value(other.value){}

Data& Data::operator=(const Data& other){
    if (this != &other)
    {
        value = other.value;
    }
    return (*this);
}

Data::~Data(){}