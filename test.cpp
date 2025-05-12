// Exactly! When you create an object and assign it a value from another temporary object
//  (whose scope ends immediately), the compiler will often use copy elision or RVO to move
//   the temporary object directly into the new object without calling the assignment
//    operator.

// In this case, no copy or assignment occurs because the compiler optimizes the process
//  by directly constructing the object in place.
#include <iostream>
class Base {
    public:
        void foo() { std::cout << "Base::foo\n"; }
};

class Derived : public Base {
    public:
        void bar() { std::cout << "Derived::bar\n"; }
};

class custom_exception : public std::exception
{
    virtual const char* what() const noexcept{
        return "My_custom_exception";
    }
};

int main() {
    // std::string word = "hello";
    // try
    // {
    //     std::cout << word.at(10);
    //     // throw custom_exception();
    // }
    // catch (int x){
    //     std::cout << x << '\n';
    // }
    // catch (std::out_of_range& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    Base* obj1 = new Derived;
    const derived obj = derived;


    obj1->makeSound();
    // obj2.makeSound();


















    return (0);
}
