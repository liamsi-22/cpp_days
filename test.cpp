
#include <iostream>
// class Base {
// public:
//     void foo() { std::cout << "Base::foo\n"; }
// };

// class Derived : public Base {
// public:
//     void bar() { std::cout << "Derived::bar\n"; }
// };

class custom_exception : public std::exception
{
    virtual const char* what() const noexcept{
        return "My_custom_exception";
    }
};

int main() {
    std::string word = "hello";
    try
    {
        std::cout << word.at(10);
        // throw custom_exception();
    }
    catch (int x){
        std::cout << x << '\n';
    }
    catch (std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
