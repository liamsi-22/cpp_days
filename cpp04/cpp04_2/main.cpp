#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    // Animal* animal = new Animal(); // this will cause a compiler err
    // animal.makeSound();

    Animal* cat = new Cat();
    Animal* dog = new Dog();

    cat->makeSound();
    dog->makeSound();
}