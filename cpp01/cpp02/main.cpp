#include <iostream>

int main(){
    std::string arg = "HI THIS IS BRAIN";
    std::string* stringPTR = &arg;
    std::string &stringREF = arg;

    std::cout << "Address of brain:     " << &arg << std::endl;
    std::cout << "Address held by PTR:  " << &stringPTR << std::endl;
    std::cout << "Address held by REF:  " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of brain:          " << arg << std::endl;
    std::cout << "Value pointed to by PTR: " << *stringPTR << std::endl;
    std::cout << "Value via the REF:       " << stringREF << std::endl;
}