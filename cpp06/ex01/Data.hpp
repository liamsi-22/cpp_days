#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
    public:
        int value;
        Data();
        Data(const Data&);
        Data& operator=(const Data&);
        Data(int);
        ~Data();
};

#endif