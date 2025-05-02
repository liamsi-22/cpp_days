// Why write the same code multiple times for int,
//  float, double, etc., when you can write it once and reuse it?"


// template :
// "I’m about to define a template, not actual code yet. This code depends on one or more types or values that will be provided later."

// typename T :
// "There is a placeholder called T, and it will be replaced with a real type (like int, double, or std::string) when this template is used."
#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
template<typename T>
void swap(T& x, T& y){
    T tmp = x;
    x = y;
    y = tmp;
}

template<typename I>
const I& min(const I& x, const I& y){
    if (x < y)
        return (x);
    else
        return (y);
}

template<typename J>
const J& max(const J& x, const J& y){
    if (x > y)
        return (x);
    else
        return (y);
}

#endif