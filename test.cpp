
#include <iostream>
class Base {
public:
    void foo() { std::cout << "Base::foo\n"; }
};

class Derived : public Base {
public:
    void bar() { std::cout << "Derived::bar\n"; }
};

int main() {
    Base* b = new Derived();
    b->bar();
}
