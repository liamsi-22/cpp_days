#include <iostream>
#include "iter.hpp"

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90};
    float arr1[] = {3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
    std::string arr2[] = {"ismail", "liam", "liamsi", "samile"};

    iter(arr, 9, increment);
}