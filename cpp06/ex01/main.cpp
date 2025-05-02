#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d(25);

    std::cout << d.value << std::endl;
    uintptr_t ser_data = Serializer::serialize(&d);
    Data* des_data = Serializer::deserialize(ser_data);

    std::cout << des_data->value << std::endl;

    return (0);
}