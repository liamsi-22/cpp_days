#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename D>
void increment(D& elm){
    std::cout << "elm before : " << elm << std::endl;
    elm++;
    std::cout << "elm after : " << elm << std::endl;
}

// template <typename D>
// void increment(D& elm){
//     std::cout << "this element of the array is : " << elm << std::endl;
// }

template <typename T>
void iter(T* arr, size_t arr_size, void (*func)(T& elm)){
    for (size_t i = 0; i < arr_size; ++i)
        func(arr[i]);
}

#endif